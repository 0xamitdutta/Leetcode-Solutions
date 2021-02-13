class Solution {
public:
    vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
        int n = workers.size();
        int m = bikes.size();
        vector<int> res(n);
        vector<vector<pair<int, int>>> dist(2001); // 2000 is max manhattan dist bcuz (Given : 0 ≤ workers[i][j], bikes[i][j] < 1000) assuming 0,0 and 1000,1000
        // For every distance from 0-2000 we have a vector of pair of worker, bike
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                dist[d].push_back({i, j});
            }
        }
        
        vector<int> assigned(n); // If a worker is assigned a bike or not
        vector<int> occupied(m); // If a bike is assigned to a worker or not
        for(int i = 0; i < 2001; i++){
            auto pairs = dist[i];
            for(auto& p : pairs){
                int w = p.first;
                int b = p.second;
                if(!assigned[w] && !occupied[b]){
                    res[w] = b;
                    assigned[w] = 1;
                    occupied[b] = 1;
                }
            }
        }
        return res;
    }
};
