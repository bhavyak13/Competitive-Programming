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
#define pi pair<int,int>
struct cmp {constexpr bool operator()(pi const& a, pi const& b)const noexcept{return a.first > b.first;}};
#define ai array<int,2>
struct cmparr {constexpr bool operator()(ai const& a, ai const& b)const noexcept{return a[0] > b[0];}};
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


// Sieve of Eratosthenes
/*
int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
*/

/*------------------------------------begin------------------------------------

*/

auto fun(){}
int n,m;
bool ok(int&x,int&y){
    return (x>=0&&x<n&&y>=0&&y<m);
}
int indx(int&x,int&y){
    return x*m+y;
}
void solve()
{
    cin>>n>>m;
    vector<string>a(n);
    ffor(i,0,n)cin>>a[i];
    int dx[]={-1,1,0,0};
    int dy[]={0,0,1,-1};
    vvi dist(n+1,vi(m+1,im));
    vvi dist2(n+1,vi(m+1,im));
    queue<ai>q;
    ffor(i,0,n){
        ffor(j,0,m){
            if(a[i][j]=='M'){
                q.push({0,indx(i,j)});// min pq multi source bfs
                dist[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        auto z=q.front();
        q.pop();
        int d=z[0];
        int x=z[1]/m,y=z[1]%m;
        if(dist[x][y]<d)continue;
        ffor(e,0,4){
            int nx=x+dx[e],ny=y+dy[e];
            if(ok(nx,ny)&&a[nx][ny]=='.'){
                if(dist[nx][ny]>d+1){
                    dist[nx][ny]=d+1;
                    q.push({d+1,indx(nx,ny)});
                }
            }
        }
    }
    vi prnt(n*m+5,-1);
    ffor(i,0,n){
        ffor(j,0,m){
            if(a[i][j]=='A'){
                priority_queue<ai,vector<ai>,cmparr>pq;
                pq.push({0,indx(i,j)});
                while(!pq.empty()){
                    auto z=pq.top();
                    pq.pop();
                    int d=z[0];
                    int x=z[1]/m,y=z[1]%m;
                    if(!x||!y||x==n-1||y==m-1){
                        pn(Y);
                        pn(d);
                        int t=z[1];
                        string ans;
                        while(prnt[t]!=-1){
                            int p=prnt[t];
                            if(p+1==t)ans.pb('R');
                            else if(p-1==t)ans.pb('L');
                            else if(p+m==t)ans.pb('D');
                            else ans.pb('U');
                            t=p;
                        }
                        reverse(all(ans));
                        pn(ans);
                        return;
                    }
                    ffor(e,0,4){
                        int nx=x+dx[e],ny=y+dy[e];
                        if(ok(nx,ny)&&a[nx][ny]=='.'&&dist[nx][ny]>d+1){
                            if(dist2[nx][ny]>d+1){
                                dist2[nx][ny]=d+1;
                                prnt[indx(nx,ny)]=indx(x,y);
                                pq.push({d+1,indx(nx,ny)});
                            }
                        }
                    }
                }
            }
        }
    }
    pn(N);
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;
    solve();
    return 0;
}