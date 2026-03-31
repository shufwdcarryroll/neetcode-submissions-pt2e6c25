class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if(intervals.empty()) return 0;
        
        // Sort intervals by their end times
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });

        int i = 1;
        int minE = intervals[0][0];
        int maxE = intervals[0][1];
        int overlap = 0;
        for(i ; i < intervals.size(); i++)
        {
             if(intervals[i][0] < maxE) overlap++;
             else
             {
             minE = min(minE,intervals[i][0]);
             maxE = intervals[i][1];
             }

        }

        return overlap;
    }
};