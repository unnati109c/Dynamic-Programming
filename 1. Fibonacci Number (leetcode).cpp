#include<bits/stdc++.h>
using namespace std;

int fibRecursive(int n)
{
	if(n==0 or n==1)
		return n;
	return fibRecursive(n-1)+fibRecursive(n-2);
}


int fibTopDownDP(int n, vector<int>&dp)
{
	if(n==0 or n==1)
		return n;

	if(dp[n]!=-1)
		return dp[n];

	return dp[n] = fibTopDownDP(n-1,dp) + fibTopDownDP(n-2,dp);
}

int fibBottomUpDP(int n)
{
	vector<int>DP(n+1,0);
	DP[0]=0;
	DP[1]=1;

	for(int i=2;i<=n;i++)
	{
		DP[i] = DP[i-1] + DP[i-2];
	}

	return DP[n];
}

int main()
{
	int n = 5;
	vector<int>dp(n+1,-1);

	cout<<fibRecursive(n)<<endl;
	cout<<fibTopDownDP(n, dp)<<endl;
	cout<<fibBottomUpDP(n)<<endl;

	return 0;
}
