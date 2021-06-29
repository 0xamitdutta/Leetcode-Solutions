class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int max_area = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;
        int area = 1;
        area += dfs(grid, i-1, j);
        area += dfs(grid, i, j+1);
        area += dfs(grid, i+1, j);
        area += dfs(grid, i, j-1);
        return area;
    }
};
