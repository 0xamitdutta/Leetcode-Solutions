/* https://www.lintcode.com/problem/meeting-rooms/description */

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval> &intervals) {
        if(intervals.size() == 0 || intervals.size() == 1) return true;
        
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){return a.start < b.start;});
        int endTime = intervals[0].second;
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i].first < endTime) 
                return false;
            endTime = intervals[i].second;
        }
        return true;
    }
};
