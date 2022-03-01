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
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < n; i++) {
            if(res.back()[0] <= intervals[i][0] && res.back()[1] >= intervals[i][1])
                continue;
            res.push_back(intervals[i]);
        }
        return res.size();
    }
    
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) 
            return a[1] > b[1];
        return a[0] < b[0];
    }
};
