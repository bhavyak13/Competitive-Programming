#include <bits/stdc++.h>
/*
Gurmeet Singh
MAIT
2024
*/
using namespace std;
#define int long long int
#define mod (int)(1e9 + 7)
#define nline "\n"
bool check(string str, int &i, char ch)
{
    char up = toupper(ch);
    char low = tolower(ch);
    bool m = false;
    while (i < str.length() && (str[i] == up || str[i] == low))
    {
        i++;
        m = true;
    }
    return m;
}
void solve()
{
    int n;
    string str;
    cin >> n;
    cin >> str;
    int i = 0;
    if (!check(str, i, 'm'))
    {
        cout << "NO" << nline;
        return;
    }
    if (!check(str, i, 'e'))
    {
        cout << "NO" << nline;
        return;
    }
    if (!check(str, i, 'o'))
    {
        cout << "NO" << nline;
        return;
    }
    if (!check(str, i, 'w'))
    {
        cout << "NO" << nline;
        return;
    }
    if(i==str.length())
    cout << "YES" << nline;
    else 
    cout<<"NO"<<nline;
}
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}