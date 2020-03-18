class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        
        int max_count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int curr = 0;
                if(grid[i][j] == 1){
                    dfs(grid, i, j, curr);
                    max_count = max(max_count, curr);
                }
            }
        }
        return max_count;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& curr){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return;
        
        curr += 1;
        grid[i][j] = 0;
        dfs(grid, i-1, j, curr);
        dfs(grid, i, j+1, curr);
        dfs(grid, i+1, j, curr);
        dfs(grid, i, j-1, curr);
    }
};
