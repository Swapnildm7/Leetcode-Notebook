class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2)
        {
            nums2.swap(nums1);
            swap(n1,n2);
        }
        int inf=INT_MAX;
        int mini=0,minl=n1;//Iterate over small array
        int partitionx;
        double ans;
        while(mini<=minl)
        {
            int i=(mini+minl)/2;
            int j=(n1+n2+1)/2-i;
            int x1,y1,x2,y2;
            if(i==0)
            {
                x1=-inf;
            }
            else
            {
                x1=nums1[i-1];
            }
            if(j==0)
            {
                y1=-inf;
            }
            else
            {
                y1=nums2[j-1];
            }
            if(i==n1)
            {
                x2=inf;
            }
            else
            {
                x2=nums1[i];
            }
            if(j==n2)
            {
                y2=inf;
            }
            else
            {
                y2=nums2[j];
            }
            if(x1<=y2&&y1<=x2)
            {
                if((n1+n2)&1)
                {
                    ans=max(x1,y1);
                }
                else
                {
                    ans=(double)((max(x1,y1))+(min(x2,y2)))/2;
                }
                break;
            }
            else if(x1>y2)
                minl=i-1;
            else
                mini=i+1;
        }
        return ans;
    }
};
// https://leetcode.com/problems/median-of-two-sorted-arrays
// https://www.youtube.com/watch?v=LPFhl65R7ww
