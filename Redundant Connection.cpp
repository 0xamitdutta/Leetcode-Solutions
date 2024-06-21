// Dfs O(n*n)
class Solution {
public:
    map<int, vector<int>> G;
    set<int> vis;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
            vis.clear();
            // Try to check if we can reach node v from node u
            if(isCycle(u, -1)) // Passing parent along with node u
                return edge;
        }
        return {};
    }
    
    bool isCycle(int src, int par){
        vis.insert(src);
        for(int adjNode : G[src]){
            if(!vis.count(adjNode)){
                if(isCycle(adjNode, src))
                    return true;
            }
            else if(adjNode != par)
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
                return edge;
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
