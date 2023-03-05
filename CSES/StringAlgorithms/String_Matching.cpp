/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
 CF handle : bhavyakawatra
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;

//input full vector
template<class T>istream& operator >> (istream &is, vector<T>& V) {for(auto &e : V)is >> e;return is;}

#define db double
#define im INT_MAX
#define ll long long
#define mod 1000000007
#define mod2 998244353
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
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
#define endl "\n"
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
#define NO "NO" 
#define int long long
#define pi pair<int,int>
struct cmp {constexpr bool operator()(pi const& a, pi const& b)const noexcept{return a.first > b.first;}};
#define ai array<int,2>
struct cmparr {constexpr bool operator()(ai const& a, ai const& b)const noexcept{return a[0] > b[0];}};
int intfloordiv(int x,int y){if(x>=0)return x/y;else return (x-y+1)/y;}

// MODULO operations: 
int modmul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int modadd(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int pwr(int a, int b) {a %= mod; int res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
int binExpo(int a,int b){
    if(!b)return 1;
    int res=binExpo(a,b/2);
    if(b&1)return modmul(a,modmul(res,res));
    else return modmul(res,res);
}
int inv(int a){return binExpo(a,mod-2);}




/*------------------------------------begin------------------------------------

*/

// rabin karp
vi rabin_karp(string a,string b){
    int n=a.sz;
    int m=b.sz;
    int p=31;
    vi hash(n+1,0);
    vi p_pow(max(n,m)+5,1);
    ffor(i,1,p_pow.sz){
        p_pow[i]=modmul(p_pow[i-1],p);
    }
    ffor(i,1,n+1){
        int h=((a[i-1]-'a'+1)*p_pow[i])%mod;
        hash[i]=(hash[i-1]+h)%mod;
    }
    int h=0;
    ffor(i,1,m+1){
        int x=modmul((b[i-1]-'a'+1),p_pow[i]);
        h=modadd(h,x);
    }
    vi occurances;
    for(int i=m;i<=n;i++){
        int h_temp=((hash[i]-hash[i-m])+mod)%mod;
        if(h_temp==h*p_pow[i-m]%mod)occurances.pb(i);
    }
    return occurances;
}

void solve()
{
    string a,b;
    cin>>a>>b;
    auto occurances=rabin_karp(a,b);
    pn(occurances.sz);
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;
    solve();
    return 0;
}