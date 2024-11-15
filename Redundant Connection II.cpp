class Solution {
public:
    vector<int> par, size;
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1); size.resize(n+1);

        vector<int> candidate1, candidate2;
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if(par[v] == 0)
                par[v] = u;
            else {
                // We cannot simply return this edge because there might be a chance there will be cycle. So we have to consider both the edges as our potential answer
                // Eg: edges = [[1, 2], [2, 3], [3, 4], [4, 2], [1, 5]] 
                candidate1 = {par[v], v};
                candidate2 = edge;
                // We are invalidating this edge
                edge[1] = 0;
            }
        }
        for(int i = 1; i <= n; i++) {
            par[i] = i, size[i] = 1;
        }
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if(v == 0) continue;

            int pu = find(u), pv = find(v);
            if(pu == pv) {
                // Cycle detected
                if(!candidate1.empty())
                    // We have invalidated second edge but still cycle is there. Hence candidate1 is the answer
                    return candidate1;
                return edge;
            }
            join(pu, pv);
        }
        // Everything is fine after invalidating second edge. Hence candidate2 is the answer
        return candidate2;
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
