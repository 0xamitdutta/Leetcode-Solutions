// Dfs O(n*n)
class Solution {
public:
    vector<int> adj[1005];
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto edge : edges){
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            vector<int> vis(1005);
            if(isCycle(a, 0, vis))
                return {a, b};
        }
        return {};
    }
    
    bool isCycle(int src, int par, vector<int>& vis){
        vis[src] = 1;
        for(int u : adj[src]){
            if(!vis[u]){
                if(isCycle(u, src, vis))
                    return true;
            }
            else if(u != par)
                return true;
        }
        return false;
    }
};

// Union-Find O(n)
class Solution {
public:
    int par[1005];
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        memset(par, -1, sizeof(par));
        for(auto edge : edges){
            int a = find(edge[0]);
            int b = find(edge[1]);
            if(a == b)
                return {edge[0], edge[1]};
            Union(a, b);
        }
        return {};
    }
    
    int find(int a){
        if(par[a] < 0) return a;
        return par[a] = find(par[a]);
    }
    
    void Union(int a, int b){
        par[a] = b;
    }
};
