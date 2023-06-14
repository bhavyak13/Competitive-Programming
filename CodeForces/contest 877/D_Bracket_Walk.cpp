/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
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

*/


/*------------------------ Segment Tree Template begin ------------------------*/

template<typename Node,typename Update>
struct SegTree{
    int n;
    vector<int>arr;
    vector<Node>tree;
    SegTree(int a_len,vector<int>&a){
        arr=a;
        n=a_len;
        int s=1;
        while(s<2*n){
            s=s<<1;
        }
        tree.resize(s);
        fill(all(tree),Node());//starting m all Nodes will have indentity value
        build_tree(0,n-1,1);
    }
    void build_tree(int l,int r,int indx){
        if(l==r){
            tree[indx]=Node(arr[l]);
            return;
        }
        int mid=(l+r)/2;
        build_tree(l,mid,2*indx);
        build_tree(mid+1,r,2*indx+1);
        tree[indx].merge(tree[2*indx],tree[2*indx+1]);
    }
    Node query(int l,int r,int indx,int qLeft,int qRight){
        if(l>=qLeft&&r<=qRight){
            return tree[indx];
        }
        if(l>qRight||r<qLeft){
            return Node();
        }
        Node left,right,ans;
        int mid=(l+r)/2;
        left=query(l,mid,2*indx,qLeft,qRight);
        right=query(mid+1,r,2*indx+1,qLeft,qRight);
        ans.merge(left,right);
        return ans;
    }
    void update(int l, int r, int indx, int qIndx, Update&u){
        if(l==r){
            u.apply(tree[indx]);
            return;
        }
        int mid=(l+r)/2;
        if(mid>=qIndx){
            update(l,mid,2*indx,qIndx,u);
        }else{
            update(mid+1,r,2*indx+1,qIndx,u);
        }
        tree[indx].merge(tree[2*indx],tree[2*indx+1]);
    }
    void make_update(int indx,int val){
        Update new_update=Update(val);
        update(0,n-1,1,indx,new_update);
    }
    Node make_query(int left,int right){
        return query(0,n-1,1,left,right);
    }

};
struct Node1{
    int val;
    Node1(){ //used during initialization and used for identity elemnt
        val=0; // -> may change
    }
    Node1(int value){ //building new nodes with this value
        val=value; // -> may change
    }
    void merge(Node1&l,Node1&r){ // l and r are child nodes
        val = l.val + r.val;  // -> may change
    }
};
struct Update1{
    int val; //store the value which was recieved during update call
    Update1(int value){ 
        val=value;
    }
    void apply(Node1&a){//applying update to given node
        a.val=val;
    }
};

/*------------------------- Segment Tree Template end -------------------------*/

// void solve(){
//     in2(n,q);
//     vi a(n);
//     ffor(i,0,n)cin>>a[i];
//     SegTree<Node1,Update1>seg(n,a);
//     while(q--){
//         in3(t,x,y);
//         if(t==1){
//             seg.make_update(x-1,y);
//         }else{
//             pn(seg.make_query(x-1,y-1).val);
//         }
//     }
// }



auto fun(){}

void solve()
{
    in2(n,q);
    pt2(n,q);
    string s;
    cin>>s;
    pn(s);
    vi a(n,0);
    
    ffor(i,0,n){
        if(s[i]=='(')a[i]=1;
        else a[i]=-1;
    }

    SegTree<Node1,Update1>seg(n,a);
    while(q--){
        in(indx);
        indx--;
        seg.make_update(indx,-1*seg.make_query(indx,indx).val);
        pn(seg.make_query(0,n-1).val);
    }

}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;
    int t=1;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}










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


//vector<string> split(string s, char delimeter) {
//	vector <string> tokens; stringstream check1(s);
//	string intermediate;
//	while (getline(check1, intermediate, delimeter)) {
//		tokens.push_back(intermediate);
//	} 
//	return tokens;
//}

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
/*

// NCR code
int MAXN;
vi factorial;
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % mod) % mod;
}
void precomputeFactorials(){
    MAXN=100006;// give max n here
    factorial.assign(MAXN+5,1);
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
    }
}
*/

// vector<int>prime_factors(int n){
// 	vector<int>ans;
// 	if(!(n%2))ans.push_back(2);
// 	while(!(n%2))n/=2;
// 	for(int i=3;i*i<=n;i+=2){
// 		if(n%i==0)ans.push_back(i);
// 		while(n%i==0)n/=i;
// 	}
// 	if(n>1)ans.push_back(n);
// 	return ans;
// }