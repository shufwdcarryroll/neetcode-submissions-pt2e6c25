class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int moneyi = money;
        sort(prices.begin(),prices.end());
        int count = 0;
        for(int i = 0 ; i < prices.size() ; i++)
        {
            if(count < 2 && (money - prices[i]) >= 0 )
            {
                count++;
                money = money - prices[i];
            }

        }

        if ( count < 2)
        {
            return moneyi;
        }

        return money;
    
    }
};