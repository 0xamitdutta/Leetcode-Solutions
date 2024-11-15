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
    vector<int> par, size;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1); size.resize(n+1);
        for(int i = 0; i < par.size(); i++) {
            par[i] = i; size[i] = 1;
        }

        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            int pu = find(u), pv = find(v);
            if(pu == pv)
                return edge;
            join(pu, pv);
        }
        return {};
    }

    int find(int x) {
        if(x == par[x])
            return x;
        return par[x] = find(par[x]);
    }

    void join(int u, int v) {
        if(size[u] > size[v]) {
            size[u] += size[v];
            par[v] = u;
        } else {
            size[v] += size[u];
            par[u] = v;
        }
    }
};
