// /*
//     Author : Bhavya Kawatra
//  Institute : MAIT
//       Dept : CST
//      Email : bhavyakawatra6@gmail.com
//  CF handle : BhavyaKawatra13
// */
// #include <bits/stdc++.h>
// using namespace std;

// #define db double
// #define im INT_MAX
// #define ll long long
// #define mod 1000000007
// #define vi vector<int>
// #define vvi vector<vi>
// #define vp vector<pair<int,int>>
// #define pb push_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define T true
// #define F false
// #define mem(x, y) memset(x, y, sizeof(x))
// #define sp(x) cout << fixed;cout << setprecision(x)
// #define sz size()
// #define mahadev ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define PI 3.14159265358979323846
// #define lb lower_bound
// #define ub upper_bound
// #define bs binary_search
// #define full_line(s) getline(cin, s)
// #define in(n) int n;cin >> n
// #define in2(a, b) int a,b;cin >> a >> b
// #define in3(a, b, c) int a,b,c;cin >> a >> b >> c
// #define in4(a, b, c,d) int a,b,c,d;cin >> a >> b >> c>>d
// #define max_heap(pq) priority_queue <int> pq
// #define min_heap(pq) priority_queue <int, vector<int>, greater<int> > pq
// #define asort(v) sort(v.begin(),v.end())
// #define dsort(v) sort(v.rbegin(),v.rend())
// #define pn(p) cout<<p<<endl
// #define pt(p) cout<<p<<" "
// #define pt2(p,q) cout<<p<<" "<<q<<endl
// #define pt3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl
// #define pt4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl
// #define vfor(v) for (auto i =v.begin() ; i!=v.end(); i++)
// #define vbfor(v) for (auto i =v.rbegin() ; i!=v.rend(); i++)
// #define ffor(i, a, b) for (int i = a; i < b; i++)
// #define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
// #define all(v) v.begin(),v.end()
// #define int long long
// int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
// int count_digit(int n){int c = 0;while (n > 0){c++;n /= 10;}return c;}
// void maxi(int &a, int &b){if (a > b){swap(a, b);}}
// int mymin(int a, int b, int c){int mini = min(a, c);return min(mini, b);}
// int mymax(int a, int b, int c){int big = max(a, c);return max(big, b);}
// // first -> decreasing order && second -> increasing order
// bool compr(const pair<int, int> &i1, const pair<int, int> i2){if (i1.first > i2.first)return true;if (i1.first == i2.first)return i1.second < i2.second;return false;}
// //sort map by value //increasing order
// bool cmp(pair<int,int>& a,pair<int, int>& b){return a.second < b.second;}
// int intfloordiv(int x,int y){if(x>=0)return x/y;else return (x-y+1)/y;}

// /*------------------------------------begin------------------------------------*/
// int a,b;
// auto ok(int mid){

// }

// void solve()
// {
//     cin>>a>>b;
//     int ans=0;
//     // while(a>0&&b>0){
//     //     maxi(a,b);
//     //     if(b>=2)b-=2;
//     //     else break;
//     //     a-=1;
//     //     ans++;
//     // }pn(ans);
//     int l=0,h=max(a,b);
//     while(l<=h){
//         int mid=(l+h)/2;
//         if(ok(mid)){}
//     }
// }

// /*-------------------------------------end-------------------------------------*/
// signed main()
// {
//     mahadev;
//     int t;
//     cin>>t;
    
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }
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
#define vfor(v) for (auto i =v.begin() ; i!=v.end(); i++)
#define vbfor(v) for (auto i =v.rbegin() ; i!=v.rend(); i++)
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(v) v.begin(),v.end()
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

auto fun(){}

void solve()
{
    in2(a,b);
    pn(min(a,min(b,(a+b)/3)));
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