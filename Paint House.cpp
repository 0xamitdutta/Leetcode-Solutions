class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;
        
        // For every house, choose a color and the minimum cost of coloring previous houses 
        for(int i = 1; i < costs.size(); i++){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
        return min(costs[n-1][0], min(costs[n-1][1], costs[n-1][2]));
    }
};
