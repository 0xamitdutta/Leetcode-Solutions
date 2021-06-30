/* https://www.lintcode.com/problem/walls-and-gates/description */

// DFS O(m*n*number of gates) 
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

// Multi-Source BFS O(m*n)
class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size(), n = rooms[0].size();
        
        queue<vector<int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0)
                    q.push({i, j, 0});
            }
        }

        vector<int> x_dir = {0, 0, 1, -1};
        vector<int> y_dir = {1, -1, 0, 0};
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int x = q.front()[0];
                int y = q.front()[1];
                int d = q.front()[2];
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int new_x = x + x_dir[i];
                    int new_y = y + y_dir[i];
                    if(new_x < 0 || new_x >= rooms.size() || new_y < 0 || new_y >= rooms[0].size() || rooms[new_x][new_y] != 2147483647)
                        continue;
                    rooms[new_x][new_y] = d+1;
                    q.push({new_x, new_y, d+1});
                }
            }
        }
    }
    
};
