class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            vector<int> interval = intervals[i];
            if(interval[0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], interval[1]);
            else
                res.push_back(interval);
        }
        return res;
    }
};
