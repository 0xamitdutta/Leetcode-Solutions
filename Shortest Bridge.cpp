class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;
    int vis[100][100] = {};
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return bfs(grid);
                }
            }
        }
        return -1;
    }
    
    bool invalid(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
            return true;
        return false;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if(invalid(grid, x, y) || grid[x][y] == 0 || vis[x][y])
            return;
        vis[x][y] = 1;
        q.push({x, y});
        for(auto dir : dirs) {
            int nx = x + dir.first, ny = y + dir.second;
            dfs(grid, nx, ny);
        }
    }
        
    int bfs(vector<vector<int>>& grid) {
        int res = 0;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(auto dir : dirs) {
                    int nx = x + dir.first, ny = y + dir.second;
                    if(invalid(grid, nx, ny) || vis[nx][ny])
                        continue;
                    if(grid[nx][ny] == 1)
                        return res;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            res++;
        }
        return -1;
    }
};
