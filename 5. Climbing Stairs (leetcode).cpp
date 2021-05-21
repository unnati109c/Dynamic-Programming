#include<bits/stdc++.h>
using namespace std;

//METHOD 1 : MEMOISATION
int dp[46];
int distinctways(int n)
{
    if(n==0) return 1;
    if(n<0) return 0;
    
    if(dp[n]!=-1)
        return dp[n];
    
    return dp[n]=distinctways(n-1)+distinctways(n-2);
}
int climbStairsTD(int n)
{
    memset(dp,-1,sizeof(dp));
    return distinctways(n);
}

//METHOD 2 : TABULATION
int climbStairsBU(int n)
{
    if(n==1)
    {
        return 1;
    }
    vector<int>dp(n+1);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];

}

int main()
{
	cout<<climbStairsTD(4)<<endl;
	cout<<climbStairsBU(4)<<endl;
	return 0;
}

/* OBSERVATION : In the above approach we have used dp array where 
dp[i]=dp[i-1]+dp[i-2]. It can be easily analysed that dp[i] is 
nothing but i^th fibonacci number. */