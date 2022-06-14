class Solution {
public:
    vector<int> G[100000];
    vector<int> vis;
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        // We need at least n-1 edges to make a Tree
        if(edges < n-1) return -1;
        
        vis.resize(100000);
        for(auto edge : connections) {
            int a = edge[0], b = edge[1];
            G[a].push_back(b); G[b].push_back(a);
        }
        // No. of operations = No. of connected components - 1
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                count++;
                dfs(i);
            }
        }
        return count - 1;
    }
    
    void dfs(int u) {
        vis[u] = 1;
        for(int v : G[u]) {
            if(!vis[v])
                dfs(v);
        }
    }
};
