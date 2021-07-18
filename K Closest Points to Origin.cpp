// O(nlogn)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), comp);
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
    
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
    } 
};

// O(nlogk)
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
