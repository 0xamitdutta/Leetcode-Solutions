class Solution {
public:
    // Floyd Warshall
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> G(n, vector<int>(n, 10001));
        for(auto edge : edges) {
            G[edge[0]][edge[1]] = edge[2];
            G[edge[1]][edge[0]] = edge[2];
        }
        for(int i = 0; i < n; i++) 
            G[i][i] = 0;
        // The outer loops helps us to choose an intermediate path from 1 to n
        for(int k = 0; k < n; k++) {
            // Two for loops create a matrix. The outer loops helps us to create n matrix
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        int minCitiesReached = n, res = 0;
        for(int i = 0; i < n; i++) {
            int citiesReached = 0;
            for(int j = 0; j < n; j++) {
                if(G[i][j] <= distanceThreshold)
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
