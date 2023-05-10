
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
void maxi(int &a, int &b)
{
    if (a > b)
    {
        swap(a, b);
    }
}

/*------------------------------------begin------------------------------------

*/

auto fun() {}

void solve()
{
    in2(n, m);
    ffor(i, 0, 100) {}
    maxi(n, m);
    int t = n * m;
    vi a(t);
    cin >> a;
    sort(all(a));

    int mn = a[0];
    int mx = a[t - 1];
    int val = mx - mn;

    ffor(i, 0, 100) {}
    int ans = (t - n) * val;

    // case 1 -> 1 mx, 2 min
    // case 2 -> 2 mx, 1 min
    int rem = n - 1;
    int x = rem * (a[t - 2] - a[0]);
    int y = rem * (a[t - 1] - a[1]);

    ans += max(x, y);
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
