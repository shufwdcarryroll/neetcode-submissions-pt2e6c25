

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // Update minPrice if a new lower price is found
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                // Otherwise calculate profit and update maxProfit if higher
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }
};
