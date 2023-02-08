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
vector<int>prime_factors(int n){
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


// factorize using seive

int N=10000007;
vi spf;
void seive(){
    spf.assign(N+1,1);
    for (int i = 2; i <= N; i++) {
        if (spf[i]==1) {// if i is prime
            spf[i]=i;
            for (int j = i * i; j <= N; j += i)
                if(spf[j]==1)spf[j] = i;
        }
    }
}
vi factorize(int n){
    vi ans;
    while(n>1){
        int fact=spf[n];
        ans.pb(fact);
        while(n%fact==0){
            n/=fact;
        }
    }
    return ans;
}
*/
// sum = xor + (2 * and)

/*------------------------------------begin------------------------------------

*/

class objc{
public:
    int w = 0;
    int i = 0;
    int n = 0;
    objc()
    {
        w = 0;
        i = 0;
        n = 0;
    }
};


auto fun(){}

void solve()
{
    in(n);
    vector<string>a;
    vector<array<int,4>>ans;
    map<ai,vi>m;
    // [0] -> hai 
    // [1] -> want


    ffor(i,0,n){
        string s;
        cin>>s;
        a.pb(s);
    }



    string s="inw";
    ffor(i,0,n){
        objc *obj;
        obj=new objc();

        for(auto x:a[i]){
            if(x=='w')obj->w++;
            else if(x=='i')obj->i++;
            else if(x=='n')obj->n++;
        }
        vector<pair<char,int>>v;
        v.pb({obj->i,'i'});
        v.pb({obj->w,'w'});
        v.pb({obj->n,'n'});
        dsort(v);

        for(int j=0;j<3;j++){
            while(v[j].ff>1){// extra -> v[j], kam -> t 
                auto t=v[2];
                if(t.ff==1)t=v[1];
                ai z={v[j].ss,t.ss};
                ai rev={t.ss,v[j].ss};
                if(m.find(rev)!=m.end()){
                    auto x=m[rev];
                    int indx=x[x.sz-1];
                    ans.push_back({i,v[j].ss,indx,t.ss});
                    if(x.sz==1)m.erase(rev);
                    else m[rev].pop_back();
                }else m[{z}].pb(i);
                if(t==v[2])v[2].ff++;
                v[j].ff--;
            }
        }
    }
    // for (auto itr =m.begin() ; itr!=m.end(); itr++){
    //     // int N=0,I=0,W=0;
    //     char a3=(char)(*itr).ff[0];
    //     char a1=(char)(*itr).ff[1];
    //     // pt2(a3,a1);
    // }
    int r=1;
    
    int t=4;
    auto itr=m.begin();
    while(itr!=m.end()){
        int hai=(*itr).ff[0];// n
        int chahie=(*itr).ff[1];// w
        // pt2(hai,chahie);
        auto vec=(*itr).ss;
        int indx=vec[vec.sz-1];
        char haie=(char)hai;
        char chahiee=(char)chahie;
        // pt3(haie,chahiee,indx);

        auto x2=m.lb({chahie});

        if(x2!=m.end()){
            int hai2=(*x2).first[0];// w
            int chahie2=(*x2).first[1];// i
            auto vec2=(*x2).ss;
            int indx2=vec2[vec2.sz-1];

            char haie1=(char)hai2;
            char chahiee1=(char)chahie2;
            // pt2(haie1,chahiee1);
            ans.pb({indx,hai,indx2,chahie});

            (*itr).second.pop_back();
            (*x2).second.pop_back();

            if((*itr).ss.sz==0){m.erase({hai,chahie});}
            if((*x2).ss.sz==0){m.erase({hai2,chahie2});}

            if(hai==chahie2&&hai2==chahie){}
            else m[{hai,chahie2}].pb(indx2);

        }
        else pn(-1);
        itr=m.begin();
    }
    pn(ans.sz);
    for(auto i:ans){
        char a1=(char)i[1];
        char a3=(char)i[3];
        pt4(i[0]+1,a1,i[2]+1,a3);
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    // mahadev;
    int t;
    cin>>t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}

/*

hai chahie

i   n 
n   w <- itr
w   i 


n   i
i   n




win  
wn n
wi i 

*/