class Solution {
public:
    bool divisorGame(int N) {
        if(N==1)
            return false;
        else if (N==2)
            return true;
        bool dp[N+1];
        dp[0]=0;
        dp[1]=0;dp[2]=1;
        for(int i=3;i<=N;i++)
        {
            dp[i]=false;
            for(int j=1;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    if(dp[i-j]==false)
                    {
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[N];
    }
};
// https://leetcode.com/problems/divisor-game
