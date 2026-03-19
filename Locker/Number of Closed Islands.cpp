class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    if(grid[i][j] == 0)
                        dfs(grid, i, j, m, n);
                }
            }
        }

        int count = 0;
        for(int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++) {
                if(grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int&m , int& n) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1)
            return;
        
        grid[i][j] = 1;
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
    }
};
