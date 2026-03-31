class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        merged.push_back(intervals[0]);

        int i = 0;
        for(vector<int> inter : intervals)
        {
            if(merged.back()[1] >= inter[0])
            {
                merged.back()[1] = max(inter[1],merged.back()[1]);
            }
            else
            {
                merged.push_back(inter);
            }

        }

        return merged;


    }
};