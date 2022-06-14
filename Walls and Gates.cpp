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
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0)
                    q.push({i, j});
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int dist = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(auto dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || rooms[nx][ny] != INT_MAX) continue;
                    rooms[nx][ny] = dist;
                    q.push({nx, ny});
                }
            }
            dist++;
        }
    }
};
