class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;  // Stores all valid combinations
        vector<int> current;          // Current combination being explored
        backtrack(nums, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int target, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target is 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Explore numbers starting from 'start' index
        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] <= target) {   // Only consider if it doesn't exceed target
                current.push_back(nums[i]);
                backtrack(nums, target - nums[i], i, current, result); // Can reuse same element
                current.pop_back(); // Backtrack
            }
        }
    }
};
