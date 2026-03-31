class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        int prev2 = 0;          // dp[i-2]
        int prev1 = nums[0];    // dp[i-1]
        
        for(int i = 1; i < nums.size(); i++) {
            int cur = max(prev1, prev2 + nums[i]); 
            prev2 = prev1;
            prev1 = cur;
        }
        
        return prev1;
    }
};
