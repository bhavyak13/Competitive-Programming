#include <bits/stdc++.h> 
using namespace std;
#define ll long long
int maxRotateFunction(vector<int> &a)
{
	ll ans=0;
	ll n=a.size();
	vector<ll>dp(n+5,0);
	ll s=0,f=0;
	for(int i=0;i<n;i++){
		s+=a[i];
		f+=i*a[i];
	}
	dp[0]=f+s-n*a[n-1];
	ans=max(ans,dp[0]);
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1]+s-n*a[n-1-i];
		ans=max(ans,dp[i]);
	}
	return ans;
	
}
