#include<bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for (long long i=a; i<n; ++i)
#define int long long
#define pb push_back
#define seea(a,n) for (long long i=0; i<n; ++i) {cin>>a[i]}
#define seev(v,n) for (long long i=0; i<n; ++i) {long long x; cin>>x; v.push_back(x);}
#define sees(s,n) for (long long i=0; i<n; ++i) {long long x; cin>>x; s.insert(x);}

void solve() {
    //Write solution here
    string s;
    cin>>s;
    stack<char> st;
    int pref=0, max_pref=0;
    forn(i,0,s.size()) {
        if (s[i]=='<') {
            st.push(s[i]);
        }
        else {
            if (!st.empty()) {
                st.pop();
                pref+=2;
                max_pref=max(pref, max_pref);
                if (st.empty()) {
                    pref=0;
                }
            }
        }
    }
    cout<<max_pref<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    cin >> T;    //Comment out if number of test cases not to be input.
    for (int I=0; I<T; ++I) {
        solve();
    }
    return 0;
}
