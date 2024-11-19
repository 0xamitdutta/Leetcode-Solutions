// O(n*n)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            int a = intervals[i][0], b = intervals[i][1];
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                
                int c = intervals[j][0], d = intervals[j][1];
                if(c <= a && d >= b) {
                    count++; break;
                }
            }
        }
        return n - count;
    }
};

// O(nlogn)
// First sort by starting time. If 2 intervals have the same start time then the interval whose ending time is greater should come first
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int count = 0;
        vector<int> currentInterval = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];
            if(currentInterval[0] <= interval[0] && currentInterval[1] >= interval[1])
                count++;
            else
                currentInterval = interval;
        }
        return intervals.size() - count;
    }
};
