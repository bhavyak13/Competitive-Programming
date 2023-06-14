 #include <bits/stdc++.h>
using namespace std;
#define mahadev ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pn(p) cout<<p<<endl

auto fun(){}

void solve()
{
    int thisisvariablename;
    cin>>thisisvariablename;
    if(thisisvariablename==2||thisisvariablename==3||thisisvariablename==4)pn("Bob");
    else pn("Alice");
}

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