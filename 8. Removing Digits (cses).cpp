//  https://cses.fi/problemset/task/1637/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define inf 1e18
#define vi vector<ll>

vi getDigits(int n) 
{
	vi v;
	while(n) 
	{
		if(n%10 != 0) 
		{
			v.pb(n%10);
		}
		n /= 10;
	}
	return v;
}

int main() {
	
	ll n;
	cin>>n;
	if(n <= 9) 
	{
		cout<<1;
		return 0;
	}
	
	vi dp(n+1, inf);
	for(int i=1;i<=9;i++)
		dp[i] = 1;

	for(int i=10;i<=n;i++) 
	{
		vi digits = getDigits(i);
		for(auto j : digits) 
		{
			dp[i] = min(dp[i], 1 + dp[i - j]);
		}
	}
	cout<<dp[n];
	
	return 0;
}
