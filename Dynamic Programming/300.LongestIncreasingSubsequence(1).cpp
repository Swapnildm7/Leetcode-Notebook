/*
	Approach: L(i)=1+max(L(j)) for all 0<=j<i
	Space: O(n)
	Time: O(n^2)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int ans=1;
        int dp[n];
	memset(dp,0,sizeof dp);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            int maxi=0;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    maxi=max(maxi,dp[j]);
                }
            }
            dp[i]=1+maxi;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
// https://leetcode.com/problems/longest-increasing-subsequence
