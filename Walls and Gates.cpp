/* https://www.lintcode.com/problem/walls-and-gates/description */

class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size();
        if(m == 0) return;
        int n = rooms[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0)
                    dfs(rooms, i, j, 0);
            }
        }
    }
    
    void dfs(vector<vector<int>>& rooms, int i, int j, int dist){
        if(i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size() || rooms[i][j] == -1)
            return;
        if(rooms[i][j] < dist)
            return;
            
        rooms[i][j] = dist;
        dfs(rooms, i-1, j, dist+1);
        dfs(rooms, i+1, j, dist+1);
        dfs(rooms, i, j+1, dist+1);
        dfs(rooms, i, j-1, dist+1);
    }
};
