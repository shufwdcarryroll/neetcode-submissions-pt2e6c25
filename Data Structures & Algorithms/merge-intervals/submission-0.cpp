class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Result vector
        vector<vector<int>> merged;
        
        // Edge case: empty input
        if(intervals.empty()) return merged;
        
        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end());
        
        // Step 2: Initialize with the first interval
        merged.push_back(intervals[0]);
        
        // Step 3: Iterate through the intervals
        for(int i = 1; i < intervals.size(); i++) {
            // If current interval overlaps with the last merged interval
            if(intervals[i][0] <= merged.back()[1]) {
                // Merge them by updating the end
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // No overlap, just add the interval
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};
