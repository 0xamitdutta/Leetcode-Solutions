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
                    if(i < grid.size()-1 && grid[i+1][j] == 1) neighbours++;    // Down neighbours
                    if(j < grid[0].size()-1 && grid[i][j+1] == 1) neighbours++; // Right neighbours
                    // Up and Left neighbours are automatically taken care of cuz we're visiting top-bottom
                }
            }
        }
        return islands*4 - neighbours*2;
    }
};
