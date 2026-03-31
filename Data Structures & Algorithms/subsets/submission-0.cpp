class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
    
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Add current subset
        result.push_back(current);
        
        for (int i = index; i < nums.size(); i++) {
            // Include nums[i]
            current.push_back(nums[i]);
            // Recurse with next index
            backtrack(i + 1, nums, current, result);
            // Backtrack (remove last element)
            current.pop_back();
        }
    }
};
