class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        for(int i = 0; i < n; i++){
            // If the node is not colored and running dfs from that node returns false, then the Graph isn't bipartite
            if(!color[i] && !dfs(graph, color, i, 1)){
                return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int u, int c){
        if(color[u]) return color[u] == c;
        
        color[u] = c;
        for(int v : graph[u]){
            if(!dfs(graph, color, v, -c)){
                return false;
            }
        }
        return true;
    }
};
