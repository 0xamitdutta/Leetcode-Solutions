class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int islands = 0;
        int neighbours = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    islands++;
                    if(i < m-1 && grid[i+1][j] == 1) neighbours++;    // Down neighbours
                    if(j < n-1 && grid[i][j+1] == 1) neighbours++;    // Right neighbours
                    // Up and Left neighbours are automatically taken care of cuz we're visiting top-bottom
                }
            }
        }
        return islands*4 - neighbours*2;
    }
};

// DFS Solution
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return perimeter(grid, i, j);
                }
            }
        }
        return 0;
    }
    
    int perimeter(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 1;
        if(grid[i][j] == -1) return 0;
        
        grid[i][j] = -1;
        int count = 0;
        count += perimeter(grid, i+1, j);
        count += perimeter(grid, i-1, j);
        count += perimeter(grid, i, j+1);
        count += perimeter(grid, i, j-1);
        return count;
    }
};
