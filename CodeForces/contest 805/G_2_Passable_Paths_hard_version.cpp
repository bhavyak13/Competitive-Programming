/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
 CF handle : BhavyaKawatra13
*/
#include <bits/stdc++.h>
using namespace std;

#define db double
#define im INT_MAX
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vp vector<pair<int,int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define T true
#define F false
#define mem(x, y) memset(x, y, sizeof(x))
#define sp(x) cout << fixed;cout << setprecision(x)
#define sz size()
#define mahadev ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define full_line(s) getline(cin, s)
#define in(n) int n;cin >> n
#define in2(a, b) int a,b;cin >> a >> b
#define in3(a, b, c) int a,b,c;cin >> a >> b >> c
#define in4(a, b, c,d) int a,b,c,d;cin >> a >> b >> c>>d
#define max_heap(pq) priority_queue <int> pq
#define min_heap(pq) priority_queue <int, vector<int>, greater<int> > pq
#define asort(v) sort(v.begin(),v.end())
#define dsort(v) sort(v.rbegin(),v.rend())
#define pn(p) cout<<p<<endl
#define pt(p) cout<<p<<" "
#define pt2(p,q) cout<<p<<" "<<q<<endl
#define pt3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl
#define pt4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl
#define vfor(v) for (auto itr =v.begin() ; itr!=v.end(); itr++)
#define vbfor(v) for (auto itr =v.rbegin() ; itr!=v.rend(); itr++)
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(v) v.begin(),v.end()
#define Y "YES" 
#define N "NO" 
#define int long long
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int count_digit(int n){int c = 0;while (n > 0){c++;n /= 10;}return c;}
void maxi(int &a, int &b){if (a > b){swap(a, b);}}
int mymin(int a, int b, int c){int mini = min(a, c);return min(mini, b);}
int mymax(int a, int b, int c){int big = max(a, c);return max(big, b);}
// first -> decreasing order && second -> increasing order
bool compr(const pair<int, int> &i1, const pair<int, int> i2){if (i1.first > i2.first)return true;if (i1.first == i2.first)return i1.second < i2.second;return false;}
//sort map by value //increasing order
bool cmp(pair<int,int>& a,pair<int, int>& b){return a.second < b.second;}
int intfloordiv(int x,int y){if(x>=0)return x/y;else return (x-y+1)/y;}

/*------------------------------------begin------------------------------------*/

/*
lets see our tree is like this
if not visualized see the problem statment pic
 1
 2
3 4
   5

we have given a query to find if [....nodes] these nodes lie on a single path or not
ex query : [2,3,4,5]
our ans is we will find both the end points of this path (ans by seeing : 3 and 5)
process :
    What we will do is we will first find the deepest node 
    here in this case it is 5 lets say it as right node.
    how?
        we can precompute hieght array. and return node with maximum height!
    then we will find the other end of this patn lets call it as left (ans by seeing : 3)
    how?
        now this is interesting, we will find 
                finalLca = lca(x,right) // ({x -> node in query array})
        and we attach one condition with this which is it should not be equal to x
        also we will maximise height of this lca to get the other end point i.e left

        and if finalLca is equal to x in a certain case,
            tht means they lie on same side, and we want other side thts why we are doin lca part
            hence we ignore this and continue our search 
        similarly by doing this for all query array we didnt get final lca then it means
        tht complete path that is given to us is like a skewed tree.
    Now so far we have calculated both end points so now we can move to our ans part
    tht is telling where all these nodes belong to a single path or not

    for evry node we will check where 
        distance[left][x] + distnce[x][right] = distnce[left][right] //try to visualize it 
        //where distnce[a][b] -> means diance btween node a and b
    nd we xcan calculate this distnce using lca esily!

    // this is distnce function written in line 170 
    int dist(int node1,int node2){
        int finalLca=lca(node1,node2);
        int lcaHeight=height[finalLca];
        int gap=height[node1]+height[node2]-2*lcaHeight;
        return gap;
    
    and if for each node x 
        distance[left][x] + distnce[x][right] = distnce[left][right] //try to visualize it 
    this condition holds true then we can say that all the query array nodes lies 
    in a single path!
*/

// lca of 2 nodes! 
int timer,v,l;
vvi g,prnt;
vi inTime,outTime,height;

void dfs(int root,int parent,int lvl){
    inTime[root]=++timer;
    prnt[root][0]=parent;
    for(int i=1;i<=l;i++){
        int intermediate=prnt[root][i-1];
        if(intermediate!=-1)
        prnt[root][i]=prnt[intermediate][i-1];
    }
    vfor(g[root]){
        if(*itr!=parent){
            dfs(*itr,root,lvl+1);
        }
    }
    height[root]=lvl;
    outTime[root]=++timer;
}

void preprocess(){
    timer=0;
    l=ceil(log2(v));
    inTime.resize(v+1);
    outTime.resize(v+1);
    height.resize(v+1);
    prnt.assign(v+1,vi(l+1,-1));
    dfs(1,-1,1);
}

//is vrtx1 ancestor of vrtx2?
bool isAncestor(int vrtx1,int vrtx2){
    return inTime[vrtx1]<=inTime[vrtx2] && outTime[vrtx1]>=outTime[vrtx2];
    //equal in case of vrtx1==vrtx2
}

int lca(int vrtx1,int vrtx2){
    if(isAncestor(vrtx1,vrtx2)){
        return vrtx1;
    }
    else if(isAncestor(vrtx2,vrtx1)){
        return vrtx2;
    }
    for(int i=l;i>=0;i--){
        if(prnt[vrtx1][i]!=-1)
        if(!isAncestor(prnt[vrtx1][i],vrtx2)){
            vrtx1=prnt[vrtx1][i];
        }
    }
    return prnt[vrtx1][0];
}

int dist(int node1,int node2){
    int finalLca=lca(node1,node2);
    int lcaHeight=height[finalLca];
    int gap=height[node1]+height[node2]-2*lcaHeight;
    return gap;
}


void solve()
{
    cin>>v;
    g.assign(v+1,vi());
    ffor(i,0,v-1){
        in2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
    preprocess();
    in(q);
    while(q--){
        in(s);
        vi a(s);
        int deepestNodeHeight=-1;
        int deepestNode=-1;
        ffor(i,0,s){
            cin>>a[i];
            if(height[a[i]]>deepestNodeHeight){
                deepestNodeHeight=height[a[i]];
                deepestNode=a[i];
            }
        }
        int endNode=-1;
        deepestNodeHeight=-1;
        ffor(i,0,s){
            if(lca(deepestNode,a[i])==a[i])continue;
            if(height[a[i]]>deepestNodeHeight){
                deepestNodeHeight=height[a[i]];
                endNode=a[i];
            }
        }
        if(endNode==-1){
            pn(Y);continue;
        }
        int gap=dist(endNode,deepestNode);
        auto ok=T;
        for(auto i:a)
            if(dist(deepestNode,i)+dist(endNode,i)!=gap){ok=F;break;}
        if(ok)pn(Y);
        else pn(N);
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}