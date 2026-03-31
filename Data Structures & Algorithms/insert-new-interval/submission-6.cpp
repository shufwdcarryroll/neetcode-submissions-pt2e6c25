class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())  return {newInterval};   // ✅ already correct

        vector<vector<int>> newInt;
        int i = 0;

        // Step 1: push all intervals before newInterval
        for(; i < intervals.size() && intervals[i][1] < newInterval[0]; i++) {   // 🔹 CHANGED loop condition
            newInt.push_back(intervals[i]);   // 🔹 directly push instead of storing inter
        }

        // Step 2: merge overlaps
        int minVal = newInterval[0], maxVal = newInterval[1];   // 🔹 initialize properly
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {      // 🔹 REPLACED your for with while
            minVal = min(minVal, intervals[i][0]);
            maxVal = max(maxVal, intervals[i][1]);
            i++;
        }
        newInt.push_back({minVal, maxVal});

        // Step 3: push the rest
        for(; i < intervals.size(); i++) {   // 🔹 this loop unchanged, just cleaner form
            newInt.push_back(intervals[i]);
        }

        return newInt;
    }
};
