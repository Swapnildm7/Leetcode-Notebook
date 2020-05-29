/*
	Time Complexity: O(n)
	Space Complexity: O(1)
	src: "https://www.geeksforgeeks.org/maximum-product-subarray-set-3"
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod=nums[0];
        int max_val=nums[0],min_val=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(max_val,min_val);
            max_val=max(max_val*nums[i],nums[i]);
            min_val=min(min_val*nums[i],nums[i]);
            max_prod=max(max_prod,max_val);
        }
        return max_prod;
    }
};
// https://leetcode.com/problems/maximum-product-subarray
