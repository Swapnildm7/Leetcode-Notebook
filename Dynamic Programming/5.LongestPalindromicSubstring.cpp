
/*	DP Solution
	Time Complexity: O(n^2)
	Space Complexity: O(n^2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        long long int n=s.size();
        vector<vector<long long int> >dp(n,vector<long long int>(n));
        long long int start=0;	// start represents starting of substring when returning
        for(long long int i=0;i<n;i++)
            dp[i][i]=1;
        long long int lenMax=1;
        for(long long int i=0;i<n;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                lenMax=2;
                start=i;
            }
        }
        for(long long int length=3;length<=n;length++)
        {
            for(long long int i=0;i<=n-length;i++)
            {
                int j=i+length-1;
                if(dp[i+1][j-1]&&s[i]==s[j])
                    {
                    dp[i][j]=1;
                    if(length>lenMax)
                        {lenMax=length;start=i;}
                    }
            }
        }
        string ss=s.substr(start,lenMax);
        return ss;
    }
};
// https://leetcode.com/problems/longest-palindromic-substring
