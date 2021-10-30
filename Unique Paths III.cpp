class Solution {
public:
    int ans = 0, empty = 1, sx, sy;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    sx = i; sy = j;
                } else if(grid[i][j] == 0)
                    empty++;
            }
        }
        dfs(grid, sx, sy);
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] < 0) 
            return;
        if(grid[i][j] == 2) {
            if(empty == 0) ans++;
            return;
        }
        
        grid[i][j] = -2;
        empty--;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        grid[i][j] = 0;
        empty++;
    }
};
