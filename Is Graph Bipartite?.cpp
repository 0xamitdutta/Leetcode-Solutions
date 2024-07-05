class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n); 
        // Doing this if the graph is not connected
        for(int i = 0; i < n; i++) {
            if(!vis[i] && !bfs(i, graph, vis))
                return false;
        }
        return true;
    }

    bool bfs(int u, vector<vector<int>>& graph, vector<int>& vis) {
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        while(!q.empty()) {
            u = q.front();
            q.pop();
            for(int v : graph[u]) {
                if(vis[v] && vis[v] == vis[u])
                    return false;
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = -1 * vis[u];
                }
            }
        }
        return true;
    }
};
