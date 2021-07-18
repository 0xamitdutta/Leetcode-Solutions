class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(auto point : points) {
            int x = point[0], y = point[1]; 
            int d = x*x + y*y;
            pq.push({d, x, y});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            res.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return res;
    }
};
