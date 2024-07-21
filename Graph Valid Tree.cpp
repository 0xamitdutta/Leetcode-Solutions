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

// Union Find
// Decrement n after each Union operation. At the end only 1 coonected component should be remaining
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        vector<int> par(n, -1);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int parU = find(u), int parV = find(v);
            if(parU == parV) 
                return false;
            doUnion(parU, parV);
            n--;
        }
        return n == 1;
    }

    int find(int node) {
        if(par[node] == -1)
            return node;
        return par[node] = find(par[node]);
    }

    void doUnion(int parU, int parV) {
        par[parV] = parU;
    }
};
