//  https://leetcode.com/problems/house-robber/

#include<bits/stdc++.h>
using namespace std;

//method 1
int robUtil (vector<int> &nums, int start, vector <int> &dp) {
    if (start>=nums.size()) 
    	return 0;
    if (dp[start]!=-1) 
    	return dp[start];
    return dp[start]=max(nums[start]+robUtil(nums, start+2, dp), robUtil (nums, start+1, dp));
}
int rob(vector<int> &nums) 
{
    if (nums.size()==1) return nums[0];
    vector <int> dp (nums.size(), -1);
    return robUtil(nums, 0, dp);
}

//method 2
int dp[104];
int robTopDownDP(vector<int>&nums, int n) // n actually represents current processing index of recursive call
{
	if(n==0) return nums[0];
	if(n==1) return max(nums[0], nums[1]);

	if(dp[n]!=-1)
		return dp[n];

	return dp[n] = max(robTopDownDP(nums,n-1), nums[n]+robTopDownDP(nums,n-2));
}

//method 3
int robBottomUpDP(vector<int>&nums)
{
	vector<int>dp(nums.size(),0);
    dp[0]=nums[0];
    
    if(nums.size()>=2)
    {
        dp[1]=max(nums[0],nums[1]); // if nums.size()=1, then we have only 1 number in array. Therefore, this line should be written inside if.
        for(int i=2;i<nums.size();i++)
        {
            dp[i]= max(dp[i-1], nums[i]+dp[i-2]);
        }
    }
    return dp[nums.size()-1];
}

int main()
{
	vector<int>arr = {2,7,9,3,1};
	memset(dp,-1,sizeof(dp));
	cout<<robTopDownDP(arr,arr.size()-1)<<endl;
	cout<<robBottomUpDP(arr)<<endl;
	cout<<rob(arr)<<endl;

	return 0;
}