class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP array where dp[i] = min coins needed to make amount i
        vector<int> dp(amount + 1, amount + 1); // Initialize with a large value
        dp[0] = 0; // Base case: 0 coins needed to make amount 0
        
        // Iterate through all amounts from 1 to amount
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[amount] is still larger than amount, it means it's impossible
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
