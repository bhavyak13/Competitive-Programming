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

/*------------------------------------begin------------------------------------*/

//segment tree
vi a;
vi seg;

void preComp(int n){
    a.resize(n);
    seg.assign(4*n+1,0);
}

int build(int indx,int l,int r){
    if(l==r) return seg[indx]=a[l];
    int mid=(l+r)/2;
    return seg[indx]=max(
        build(2*indx+1, l, mid),
        build(2*indx+2, mid+1, r)
    );
}

int query(int indx,int low,int high,int l,int r){
    
    //completely lies
    if(low>=l&&high<=r){
        return seg[indx];
    }
    
    //doesnt lies
    if(low>r||high<l)
        return INT_MIN;
    
    //overlaps
    int mid=(low+high)/2;
    return max(
        query(2*indx+1,low,mid,l,r),//left
        query(2*indx+2,mid+1,high,l,r)//right
    );
}

auto fun(){}

void solve()
{
    in2(n,m);
    preComp(m);
    ffor(i,0,m)cin>>a[i];
    int maxPossibleHeight=n;
    build(0,0,m-1);
    in(q);
    while(q--){
        in4(rs,cs,rf,cf);
        in(k);
        if(abs(rf-rs)%k==0&&abs(cf-cs)%k==0){
            cs--;cf--;
            int maxHeightBlocked=query(0,0,m-1,min(cs,cf),max(cs,cf));
            int reachableHeight=rs+((maxPossibleHeight-rs)/k)*k;
            if(maxHeightBlocked<reachableHeight){pn(Y);continue;;}
        }
        pn(N);
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;
    solve();
    return 0;
}