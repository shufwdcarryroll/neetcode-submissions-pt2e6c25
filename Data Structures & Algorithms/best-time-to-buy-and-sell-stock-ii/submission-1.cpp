class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int s = prices[0];
        int totalP = 0;
        for(int p : prices)
        {
            s = min(p,s);
            maxP = max(maxP, p - s);
            if((p - s) > 0)
            {
                totalP = totalP + maxP;
                s = p;
                maxP = 0;
            }
        }

        return totalP;
    }
};