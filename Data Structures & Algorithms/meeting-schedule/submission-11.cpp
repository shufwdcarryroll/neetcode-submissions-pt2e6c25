/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        bool can = true;
        if(intervals.size() <= 1) return can;

        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });
        
        for(int i = 0 ; i < (intervals.size() -1) ; i++)
        {
                int end1 = intervals[i].end;
                int start2 = intervals[i+1].start;

                if(start2 < end1)
                {
                    return false;
                    break;
                }
        }

        return can;
    }
};
