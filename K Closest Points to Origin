class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, pair<int, int>> > pq;
        for(auto point : points){
            int x = point[0];
            int y = point[1];
            int d = x*x + y*y;
            pq.push({d, {x, y}});
            if(pq.size() > K)
                pq.pop();
        }
        
        vector<vector<int>> res;
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            res.push_back({x, y});
            pq.pop();
        }
        return res;
    }
};
