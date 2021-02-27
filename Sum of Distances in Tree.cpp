class Solution {
public:
    vector<int> adj[10000];
    vector<int> countOfSubtreeNodes, subTreeDistanceSum;
    // countOfSubtreeNodes is the number of subtree nodes include the current node
    // subTreeDistanceSum is the sum of distances from all the subtree nodes
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        countOfSubtreeNodes.resize(N);
        subTreeDistanceSum.resize(N);
        for(auto edge : edges){
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs1(0, -1); // Fills up the countOfSubtreeNodes and subTreeDistanceSum. But subTreeDistanceSum only works for root now.
        dfs2(0, -1); // This call handles subTreeDistanceSum for all other nodes.
        return subTreeDistanceSum;
    }
    
    void dfs1(int u, int par){
        for(int v : adj[u]){
            if(v != par){
                dfs1(v, u);
                countOfSubtreeNodes[u] += countOfSubtreeNodes[v];
                subTreeDistanceSum[u] += subTreeDistanceSum[v] + countOfSubtreeNodes[v];
            }
        }
        countOfSubtreeNodes[u]++;
    }
    
    void dfs2(int u, int par){
        for(int v : adj[u]){
            if(v != par){
                // You're one step closer to all the nodes in your subtree. Hence (subtract) countOfSubtreeNodes[v] from parent. 
                // But you're one step far from every other node. Hence (add) total nodes - countOfSubtreeNodes[v]
                subTreeDistanceSum[v] = (subTreeDistanceSum[u] - countOfSubtreeNodes[v]) + (countOfSubtreeNodes.size()-countOfSubtreeNodes[v]);
                dfs2(v, u);
            }
        }
    }
};
