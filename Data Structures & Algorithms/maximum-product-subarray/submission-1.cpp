class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minP = nums[0];
        int maxP = nums[0];
        int ans = nums[0];

        for(int i = 1 ; i < nums.size(); i++)
        {
            int prevMax = maxP;
            int prevMin = minP;

            maxP = max(nums[i],max(prevMax * nums[i], prevMin * nums[i]));
            minP = min(nums[i],min(prevMax * nums[i], prevMin * nums[i]));
            ans = max(maxP,ans);
        };

        return ans;
    }
};