class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Instead of finding the distance of each cell from all the thieves, we can do the opposite: find the distance of all the thieves from each cell.
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                } 
                else {
                    grid[i][j] = -1;
                }
            }
        }
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int nx = x + dir[j][0], ny = y + dir[j][1];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == -1) {
                        grid[nx][ny] = grid[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        

        // Do a binary search on the safeNess values on grid to get the answer
        int maxSafeness = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                maxSafeness = max(maxSafeness, grid[i][j]);
        }

        int low = 0, high = maxSafeness, ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(isPossible(grid, mid, m, n)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    bool isPossible(vector<vector<int>>& grid, int value, int& m, int& n) {
        if(grid[0][0] < value || grid[m-1][n-1] < value)
            return false;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;

        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x == m-1 && y == n-1)
                return true;
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] >= value && !vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
        return false;
    }
};
