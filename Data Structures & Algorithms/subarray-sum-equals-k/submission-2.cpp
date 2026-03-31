class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int res = 0;
       int currentSum = 0;
       unordered_map<int,int> preFixSum;
       preFixSum[0] = 1;

       for(int num : nums) 
       {
        currentSum += num;

        if(preFixSum.find( currentSum - k) != preFixSum.end())
        {
            res += preFixSum[currentSum-k];
        }

        preFixSum[currentSum]++;
       }

       return res;
    }
};