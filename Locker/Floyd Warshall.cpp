// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, 10001));
        for(auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2]
            dis[u][v] = w;
            dis[v][u] = w;
        }
        for(int i = 0; i < n; i++) 
            dis[i][i] = 0;
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int minCitiesReached = n, res = 0;
        for(int i = 0; i < n; i++) {
            int citiesReached = 0;
            for(int j = 0; j < n; j++) {
                if(dis[i][j] <= distanceThreshold)
                    citiesReached++;
            }
            if(citiesReached <= minCitiesReached) {
                minCitiesReached = citiesReached;
                res = i;
            }
        }
        return res;
    }
};
