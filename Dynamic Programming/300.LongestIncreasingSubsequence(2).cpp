/*
	Only works for returning longest subsequence length
	Approach: For current element put it at it's right place by deleting it's just greater element
	Time: O(NlogN)
	Space: O(N)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int len=1;
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            int nn=dp.size();
            int l=0,r=nn-1;
            int x=nums[i];
            while(l<=r)
            {
                int m=l+(r-l)/2;
                if(dp[m]<x)
                    l=m+1;
                else if(dp[m]>x)
                    r=m-1;
                else
                {
                    break;
                }
            }
            if(l>r)
            {
                if(l<nn)
                dp[l]=x;
                else
                {
                    len++;
                    dp.push_back(x);
                }
            }
        }
        return len;
    }
};
// https://leetcode.com/problems/longest-increasing-subsequence
