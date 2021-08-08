class Solution {
public:
    vector<int> adj[10000];
    vector<int> vis;
    bool validTree(int n, vector<vector<int>> &edges) {
        int m = edges.size();
        if(m != n-1) return false;
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vis.resize(n);

        if(isCycle(0, -1)) return false;
        for(int& num : vis) {
            if(num == 0) return false;
        }
        return true; 
    }
    
    bool isCycle(int u, int par){
        vis[u] = 1;
        for(int v : adj[u]){
            if(!vis[v] && isCycle(v, u)){
                if(isCycle(v, u))
                        return true;
            }
            else if(v != par)
                return true;
        }
        return false;
    }
};
