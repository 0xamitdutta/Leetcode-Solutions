class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> adj[N+1];
        vector<int> color(N+1);
        for(auto dislike : dislikes){
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }        
        for(int i = 1; i <= N; i++){
            if(!color[i] && !dfs(adj, color, i, 1))
                return false;
        }
        return true;
    }
    
    bool dfs(vector<int> adj[], vector<int>& color, int v, int c){
        if(color[v] != 0)
            return color[v] == c;
        
        color[v] = c;
        for(int child : adj[v]){
            if(!dfs(adj, color, child, -c))
                return false;
        }
        return true;
    }
};
