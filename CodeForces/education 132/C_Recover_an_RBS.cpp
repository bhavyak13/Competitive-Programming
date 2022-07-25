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

// main idea was tht
/*
Question:

notice tht it was coming from an RBS (regular bracket sequnce)
and from there some brackets have been marked as ? 
Now you can to say if it is possible to get only 1 string (i.e string on which ? have been imposed) from 
this ? wali string or 
u can get multiple strings form this ? wali string

Approach:

notice if we replace first a question marks with '(' and
remaining b question marks with ')' then we alwys get a rbs

a-> number of opening brackets possible!
b-> number of closing brackets possible!

now we have to find is this rbs unique or not!

so wht we can do is we swap the last opening bracket with first occurance of closing bracket
and now we find if this is an rbs if it founds to be a rbs tht means atleast 1 rbs can be formed form this ? wali string 
iwhich in turns means NO to unique RBS 
and we got our ans;

and if it not found to unique then it means only 1 rbs can be formed which in turn means 
we get back our original string hence we simply print YES

*/


bool check(string s){
    int bal=0;
    for(auto i:s){
        if(i=='(')bal++;
        else bal--;
        if(bal<0)return false;
    }
    return true;
}

void solve()
{
    string s;
    cin>>s;
    int n=s.sz/2;
    int o=0,c=0;
    vi pos;
    int i=0;
    vfor(s){
        if(*itr=='(')o++;
        else if(*itr==')')c++;
        else pos.pb(i);
        i++;
    }
    // we are checking for (( )( ))
    o=n-o;
    c=n-c;

    for(int i=0;i<pos.size();i++){
        if(i<o)s[pos[i]]='(';
        else s[pos[i]]=')';
    }

    if(o>=1&&c>0){
        swap(s[pos[o-1]],s[pos[o]]);
        if(check(s)){pn(N);return;}
    }
    pn(Y);
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