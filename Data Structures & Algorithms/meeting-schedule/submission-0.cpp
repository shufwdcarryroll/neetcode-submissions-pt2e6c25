class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // Step 2: Check for any overlaps
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;  // Overlap found
            }
        }

        return true;  // No overlaps
    }
};
