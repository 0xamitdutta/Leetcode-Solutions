/* https://www.lintcode.com/problem/meeting-rooms-ii/description */

/*
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        if(intervals.size() == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto interval : intervals){
            if(!pq.empty() && interval.start >= pq.top())
                pq.pop();
            pq.push(interval.end);
        }
        return pq.size();
    }
};
