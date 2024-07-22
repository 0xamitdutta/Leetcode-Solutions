// DFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // We can do DFS directly on adjacency matrix but it's more easy on adjacency list
        unordered_map<int, vector<int>> G;
        int n = isConnected.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] && i != j) {
                    G[i].push_back(j);
                } else if(isConnected[i][j] && i == j && !G.count(i)) {
                    G[i] = {};
                } 
            }
        }

        int count = 0;
        unordered_set<int> vis;
        for(auto& [key, val] : G) {
            if(!vis.count(key)) {
                dfs(key, vis, G);
                count++;
            }
        }
        return count;
    }

    void dfs(int node, unordered_set<int>& vis, unordered_map<int, vector<int>>& G) {
        vis.insert(node);
        for(int& nbr : G[node]) {
            if(!vis.count(nbr))
                dfs(nbr, vis, G);
        }
    }
};
