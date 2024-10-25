class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs, int n, int colors) {
        if(n == 0) return 0;
        
        // For every house, choose a color and the minimum cost of coloring previous houses 
        for(int i = 1; i < costs.size(); i++){
            for(int j = 0; j < colors; j++) {
                int minCost = INT_MAX;
                for(int k = 0; k < colors; k++) {
                    if(j == k) continue;
                    minCost = min(minCost, costs[i-1][k];
                }
                costs[i-1][j] += minCost;
            }
        }
        int res = costs[n-1][0];
        for(int j = 1; j < colors; j++) {
            res = min(res, costs[n-1][j]);
        }
        return res;
    }
};
