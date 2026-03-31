class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int profit = 0;

      int curPrice = prices[0];

      for(int num : prices)
      {
        curPrice = min(num,curPrice);
       

        if( num - curPrice > 0)
        { 
            profit += ( num - curPrice); 
            curPrice = num;
        }
      }

      return profit;
    }
};