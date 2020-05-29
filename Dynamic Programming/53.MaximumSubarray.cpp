/*
	Space: O(n)
	Time: O(n)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        int dp[n];
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=nums[i]+max(0,dp[i-1]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
// https://leetcode.com/problems/maximum-subarray
