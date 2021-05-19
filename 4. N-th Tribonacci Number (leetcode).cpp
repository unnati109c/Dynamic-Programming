//  https://leetcode.com/problems/n-th-tribonacci-number/

#include<bits/stdc++.h>
using namespace std;

int tribonacciRecursive(int n)  // gives TLE 
{
	if(n<=0)
		return n;
	if(n==1 or n==2)
		return 1;
	return tribonacciRecursive(n-1) + tribonacciRecursive(n-2) + tribonacciRecursive(n-3);

}

//int dp[38]={0};
vector<int>dp(38);
int tribonacciTopDownDP(int n)
{
	if(n<=0)
		return n;
	if(n==1 or n==2)
		return 1;
	if(dp[n]!=0)
		return dp[n];

	return dp[n] = tribonacciTopDownDP(n-1) + tribonacciTopDownDP(n-2) + tribonacciTopDownDP(n-3);
}

int tribonacciBottomUpDP(int n)
{
	vector<int>dp(38);
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    
    for(int i=3;i<=n;i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    
    return dp[n];
}

int main()
{
	int n;
	cin>>n;

	cout<<tribonacciRecursive(n)<<endl;
	cout<<tribonacciTopDownDP(n)<<endl;
	cout<<tribonacciBottomUpDP(n)<<endl;

	return 0;
}