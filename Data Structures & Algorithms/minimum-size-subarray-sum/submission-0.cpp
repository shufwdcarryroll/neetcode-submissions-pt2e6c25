class Solution {
public:

    vector<int> prefixSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + nums[i];
    return prefix;
   }

    int minSubArrayLen(int target, vector<int>& nums) {

       vector<int> preFix =  prefixSum(nums);

       int minL = 0;
       int curL = 0;
       int start = 0;
       int end = 0;

       while(end < nums.size())
       {
           int sum = preFix[end+1] - preFix[start];

           if(sum >= target)
           {
             curL = end - start + 1;
             if(minL == 0 )
             {
                minL = curL;
             }
             else
             {
                minL = min(minL, curL);
             }
             start++;
           }
             else
             {
                end = end +1;
             }
           }
                  return minL;

       }

    
};


// 1,4,4
// prefix 1,5,9
// start = 0 , end = 0, while end < lengtth
// 