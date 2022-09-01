/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
 CF handle : BhavyaKawatra13
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;

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
vector<int>factor(int n){
    vector<int>ans;
    if(!(n%2))ans.push_back(2);
    while(!(n%2))n/=2;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0)ans.push_back(i);
        while(n%i==0)n/=i;
    }
    if(n>1)ans.push_back(n);
    return ans;
}


/*------------------------------------begin------------------------------------*/



/*
n=7

_ _ _ | 0 | _ _ _

O E O E O E O
O -> 4
E -> 3

k=8
uppr=16

odd -> 8 9   XOR = 1
even -> 13 14  XOR = 3
#claim
*/

// k=16 -> 16 17 
vi fun(int k,int siz,int d){
    siz--;
    vi ans;
    bool ok=true;
    int Xor=0,t=k;
    while(ok){
        int temp=t;
        ffor(i,0,siz){
            Xor=Xor^temp;
            ans.pb(temp++);
        }
        if(Xor!=d&&Xor)break;
        ans.resize(0);
        Xor=0;
        t++;
    }
    ans.pb(Xor);
    return ans;
}

vi fun2(int k,int siz){
    vi ans;
    int Xor=0,t=k;
    int temp=t;
    ffor(i,0,siz){
        Xor=Xor^temp;
        ans.pb(temp++);
    }
    return ans;
}
void solve()
{
    in(n);
    if(n==3){
        pn("2 1 3");return;
    }
    int k=1,ans=0;
    while(k<n)k=k<<1;
    k=k<<1;
    int rem=n%4;
    if(rem==3||rem==2){
        // 10/2 -> 5 5
        // 7/2 -> 3 3 1(0)
        vi odd,even;
        int pairSize=n/2;
        odd=fun(k,pairSize,-1);//size=3
        even=fun(k+k/2+1,pairSize,*odd.rbegin());//size=3
        int x=0,y=0;
        ffor(i,0,pairSize){
            pt(odd[i]);
            pt(even[i]);
        }
        if(rem==3)pn(0);
        else cout<<endl;
    }
    if(rem==0||rem==1){
        // 8 -> 4 4
        // 9 -> 4 4 1(0)
        vi odd,even;
        int pairSize=n/2;
        odd=fun2(k,pairSize);//size=4
        even=fun2(k+k/2,pairSize);//size=4
        ffor(i,0,pairSize){
            pt(odd[i]);
            pt(even[i]);
        }
        if(rem==0)cout<<endl;
        else pn(0);
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;
    int t;
    cin>>t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}