
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// input full vector
template <class T>
istream &operator>>(istream &is, vector<T> &V)
{
    for (auto &e : V)
        is >> e;
    return is;
}

#define db double
#define im INT_MAX
#define ll long long
#define mod 1000000007
#define mod2 998244353
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vp vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define T true
#define F false
#define mem(x, y) memset(x, y, sizeof(x))
#define sp(x)      \
    cout << fixed; \
    cout << setprecision(x)
#define sz size()
#define mahadev                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define PI 3.14159265358979323846
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define full_line(s) getline(cin, s)
#define in(n) \
    int n;    \
    cin >> n
#define in2(a, b) \
    int a, b;     \
    cin >> a >> b
#define in3(a, b, c) \
    int a, b, c;     \
    cin >> a >> b >> c
#define in4(a, b, c, d) \
    int a, b, c, d;     \
    cin >> a >> b >> c >> d
#define max_heap(pq) priority_queue<int> pq
#define min_heap(pq) priority_queue<int, vector<int>, greater<int>> pq
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.rbegin(), v.rend())
#define endl "\n"
#define pn(p) cout << p << endl
#define pt(p) cout << p << " "
#define pt2(p, q) cout << p << " " << q << endl
#define pt3(p, q, r) cout << p << " " << q << " " << r << endl
#define pt4(p, q, r, s) cout << p << " " << q << " " << r << " " << s << endl
#define vfor(v) for (auto itr = v.begin(); itr != v.end(); itr++)
#define vbfor(v) for (auto itr = v.rbegin(); itr != v.rend(); itr++)
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(v) v.begin(), v.end()
#define Y "YES"
#define NO "NO"
#define int long long

/*------------------------------------begin------------------------------------

*/

auto fun() {}

void solve()
{
    ffor(i,0,100){}
    in2(n, capacity);
    vi a(n);
    cin >> a;
    int f = 0, s = 0;
    map<int, int> M;
    ffor(i, 0, n)
    {
        if (a[i] == -1)
            f++;
        else if (a[i] == -2)
            s++;
        else
            M[a[i]]++;
    }
    ffor(i,0,100){}
    int ans = 0;
    int alreadySitted = M.sz;
    // case 1 -> -2 goes in first means 1st seat occupy then right right
    // in this case -1 no role..
    ans = min(capacity, alreadySitted + s);
    // case 2 -> -1 goes in first means last seat occupy then left left
    // in this case -2 no role..
    ans = max(ans, min(capacity, alreadySitted + f));
    // case 3 both comes.. -1,-2

    int left = 0;
    int right = alreadySitted - 1;
    for (auto i : M)
    {
        int e = i.ff;
        int leftAcc = min(f + left, e - 1);
        int rightAcc = min(s + right, capacity - e);
        ans = max(ans, leftAcc + rightAcc + 1);
        left++;
        right--;
    }

    pn(ans);
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
