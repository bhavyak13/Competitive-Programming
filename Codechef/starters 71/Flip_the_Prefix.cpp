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

//input full vector
template<class T>istream& operator >> (istream &is, vector<T>& V) {for(auto &e : V)is >> e;return is;}

#define db double
#define im INT_MAX
#define ll long long
#define mod 1000000007
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
#define N "NO" 
#define int long long
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int count_digit(int n){int c = 0;while (n > 0){c++;n /= 10;}return c;}
void maxi(int &a, int &b){if (a > b){swap(a, b);}}
int mymin(int a, int b, int c){int mini = min(a, c);return min(mini, b);}
int mymax(int a, int b, int c){int big = max(a, c);return max(big, b);}
// first -> decreasing order && second -> increasing order
bool cmp1(const pair<int, int> &i1, const pair<int, int> i2){if (i1.first > i2.first)return true;if (i1.first == i2.first)return i1.second < i2.second;return false;}
//sort vector by second value //increasing order
bool cmp2(pair<int,int>& a,pair<int, int>& b){return a.second < b.second;}
// priority_queue of pairs (min) 
struct cmp {constexpr bool operator()(pair<int, int> const& a,pair<int, int> const& b)const noexcept{return a.first > b.first;}};
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
// (a / b) % mod != (a% mod) / (b% mod).
// So we use Modular Multiplicative Inverse, i.e (A / B) % mod = A * ( B ^ -1 ) % mod
// for prime modulus m : (a^(m-2) = a^-1) mod m
int inv(int a){return binExpo(a,mod-2);}


/*------------------------------------begin------------------------------------

2 baar m    
1 0 0 0 1 0 0 0 0 1 0 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 
100010000101111110111111111
1 +3 1 +4 1 +1 6 +1 9
2:
(1 +3 1) +4 1 +1 6 +1 9  
1 +3 (1 +4 1) +1 6 +1 9
4:
(1 +3 1 +4 1) +1 6 +1 9  
1 +3 (1 +4 1 +1 6) +1 9

1:
1 (+3 1) +4 1 +1 6 +1 9
1 +3 (1 +4) 1 +1 6 +1 9
3:
1 (+3 1 +4) 1 +1 6 +1 9
1 +3 1 (+4 1 +1) 6 +1 9

0 1 1 0 1 (0 0 0 0 0 0)
(+1 2) + 1

0 0 0 1 0 1
+3 1 +1 1 +1 1 +1 1 +1 1

ODD
1 
(+3 1) +1 1 +1 1 +1 1 +1 1
(+3 1) (+1 1)
3
+3 1 +1 1 +1 1 +1 1 +1 1 
(+3 1 +1 1) +1 1 +1 1 +1 1 
+3 1 (+1 1 +1 1) +1 1 +1 1 

EVEN
4
0 0 0 1 0 1 0 1 0 1 0 1
000101010101
m=4
 0  1 2  3 4 5  6
+3 (1 +1 1 +1 1) +1 1 +1 1
+3 1 +1 (1 +1 1 +1 1) +1 1
00010001




1 10 6
0000010101
5
*/

int K;
string s;
vi a;
bool firstZero;

bool fun(int m){
    int n=a.sz;
    // pn(m);
    if(m>=n)return T;
    int ts=0;
    ffor(i,0,min(m,n)){
        ts+=a[i];
    }
    if(ts>=K)return T;
    if(firstZero){
        int s=0;
        int i=m+1;
        if(m%2){
            ffor(i,0,min(n,m+1)){
                s+=a[i];
            }
            if(s>=K)return T;
            while(i<n){
                s+=a[i];
                if(i+1<n)s+=a[i+1];
                s-=a[i-m];
                s-=a[i-m-1];
                if(s>=K)return T;
                i+=2;
            }
        }
        else{
// m=4
//  0  1 2  3 4 5  6
// +3 (1 +1 1 +1 1) +1 1 +1 1
// +3 1 +1 (1 +1 1 +1 1) +1 1
            int ts=0;
            ffor(i,0,min(m,n)){
                ts+=a[i];
            }
            if(ts>=K)return T;


            ffor(i,1,min(n,m+2)){
                s+=a[i];
            }
            i=m+2;

            if(s>=K)return T;
            while(i<n){
                s+=a[i];
                if(i+1<n)s+=a[i+1];
                s-=a[i-m];
                s-=a[i-m-1];
                if(s>=K)return T;
                i+=2;
            }
        }
        
    }else{
        if(m==1){
            ffor(i,1,n){
                int s=a[i];
                if(i+1<n)s+=a[i+1];
                if(s>=K)return T;
            }
        }else if(m%2==0){
            int s=0;
            ffor(i,0,min(n,m+1)){
                s+=a[i];
            }
            if(s>=K)return T;
            int i=m+1;
            while(i<n){
                s+=a[i];
                if(i+1<n)s+=a[i+1];
                s-=a[i-m];
                s-=a[i-m-1];
                if(s>=K)return T;
                i+=2;
            }
        }else{
            int s=0;
            ffor(i,1,min(n,m+2)){
                s+=a[i];
            }
            if(s>=K)return T;
            int i=m+2;
            while(i<n){
                s+=a[i];
                if(i+1<n)s+=a[i+1];
                s-=a[i-m];
                s-=a[i-m-1];
                if(s>=K)return T;
                i+=2;
            }
        }
    }
    // pn("FALSE");
    return false;

}

void solve()
{
    in2(n,k);
    K=k;
    cin>>s;
    a.clear();
    int i=0;
    firstZero=(s[0]=='0');
    while(i<n){
        char e=s[i];
        int c=0;
        while(i<n&&s[i]==e){
            c++;
            i++;
        }
        a.pb(c);
    }

    int l=-1,r=n;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(fun(mid))r=mid;
        else l=mid;
    }
    pn(r);

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
/*
1 -> 1s + include any +1 
2 -> include any '+' to answer
3 -> include any '+' to ans + 1s  -> goto any + capture neighbour and left plus



7 +1 7

k=15







worst case:
10101010101010
k=n -> ans : 2*n

1 (0 0 0 0 0) 1 1 1 1
k=5
ans : 1

1010

0101 -> 1
1011 -> 2

0101 -> 3
1111 -> 4

*/

            /*
            4:
                (1 +3 1 +4 1) +1 6 +1 9  
                1 +3 (1 +4 1 +1 6) +1 9
                0 1   2 3 4  5  6
            */