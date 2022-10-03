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


/*------------------------------------begin------------------------------------*/

auto fun(){}
int dig(int n){int c = 0;while (n > 0){c++;n /= 10;}return c;}

void solve()
{
    in(n);
    vi a(n);
    map<int,int>m1;
    map<int,int>m;
    ffor(i,0,n){
        cin>>a[i];
        m[a[i]]++;
    }
    
    vi b(n);
    ffor(i,0,n){
        cin>>b[i];
        if(m[b[i]]>0)m[b[i]]--;
        else m1[b[i]]++;
    }

    int ans=0;
    vi a1;
    for(auto i:m){
        int c=i.ss;
        while(c--)a1.pb(i.ff);
    }

    for(auto i:a1){
        // pt3(i,ans,m1.sz);
        if(i==1)continue;
        if(i<=9){
            // 2 -> 2 digit no
            int x=i-1,p=1;
            while(x--)p=p*10;
            auto itr=m1.lb(p);
            if(itr!=m1.end()&&(itr->ff)<p*10){ // x digit number -> x // 13 -> 2 
                ans++;
                if(itr->ss==1)m1.erase(itr);
                else m1[itr->ff]--;
            }
            else ans++; // 2 -> 1
        }
        else{
            // 12 -> 2 ->>>2 numb lower exact dig
            int d=dig(i);
            auto itr1=m1.find(d);
            if(itr1!=m1.end()){
                if(itr1->ss==1)m1.erase(itr1);
                else m1[d]--;
                ans++;
                continue;
            }
            // 12 -> 10 <-> same digit numbers
            int x=d-1,p=1;
            while(x--)p=p*10;
            auto itr=m1.lb(p);
            if(itr!=m1.end()&&itr->ff<p*10){
                if(itr->ss==1)m1.erase(itr);
                else m1[itr->ff]--;
                ans+=2;
                continue;
            }
            ans+=2;
        }
        
    }
    for(auto i:m1){
        if(i.ss>0&&(i.ff!=1)){
            if(i.ff<=9)ans+=i.ss;
            else ans+=2*i.ss;
        }
    }
    pn(ans);
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
75019 709259 5 611271314 9024533 81871864 9 3 6 4865 
9503 2 371245467  7 37376159 8 364036498 52295554 169 6



75019  5 611271314  81871864 9 3 4865 
9503 2 371245467   37376159 8 364036498 52295554 169 ->8

106 284 195 28 56 172 65 76 56 200 3 206 39 46 13 227 27 33 22 40 251 123
191 185 46 175 30 163 72 151 188 242 210 295 208 123 157 185 17 123 195 51 124 238



106 284 195 28 56 172 65 76 56 200 3 206 39 46 13 227 27 33 22 40 251 123
191 185 46 175 30 163 72 151 188 242 210 295 208 123 157 185 17 123 195 51 124 238

*/