class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 1; i <= n ; i++)
        {
            int target = i;
            for(int j = 1; j * j <= target ; j++ )
            {
                dp[target] = min(dp[target], 1 + dp[target - j*j]);
            }
        }

        return dp[n];
    }
};