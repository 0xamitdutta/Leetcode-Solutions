class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edgeList) {
        unordered_map<int, vector<int>> graph;
        for(auto& edge : edgeList) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int nodes = 0, edges = 0;
                dfs(i, graph, vis, nodes, edges);
                // If every node is connected to every other node, the total number of edges will be n * (n-1)
                if(nodes * (nodes - 1) == edges)
                    res++;
            }
        }
        return res;
    }

    void dfs(int u, unordered_map<int, vector<int>>& graph, vector<int>& vis, int& nodes, int& edges) {
        vis[u] = 1;
        nodes++;
        edges += graph[u].size();
        
        for(int v : graph[u]) {
            if(!vis[v])
                dfs(v, graph, vis, nodes, edges);
        }
    }
};
