// Dfs O(n*n)
class Solution {
public:
    map<int, vector<int>> G;
    set<int> vis;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
            vis.clear();
            if(isCycle(e[0], 0))
                return e;
        }
        return {};
    }
    
    bool isCycle(int u, int par) {
        vis.insert(u);
        for(int v : G[u]){
            if(!vis.count(v)){
                if(isCycle(v, u))
                    return true;
            }
            else if(v != par)
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
