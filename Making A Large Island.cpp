class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> colorSize;
        int color = 2;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int size = getSize(grid, i, j, color);
                    colorSize[color] = size;
                    color++;
                }
            }
        }

        int res = colorSize.count(2) ? colorSize[2] : 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    // We use a set to avoid repeatly adding islands with the same color
                    unordered_set<int> colors;
                    // Check If current island is at the boundary
                    if(i > 0) colors.insert(grid[i-1][j]);
                    if(j > 0) colors.insert(grid[i][j-1]);
                    if(i < m-1) colors.insert(grid[i+1][j]);
                    if(j < m-1) colors.insert(grid[i][j+1]);
                    
                    // We need to count current island as well, hence we init newSize with 1
                    int newSize = 1;
                    for(int color : colors)
                        newSize += colorSize[color];
                    res = max(res, newSize);
                }
            }
        }
        return res;
    }

    int getSize(vector<vector<int>>& grid, int i, int j, int color) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
            return 0;
        grid[i][j] = color;
        return 1 + getSize(grid, i+1, j, color) + getSize(grid, i-1, j, color) + getSize(grid, i, j+1, color) + getSize(grid, i, j-1, color);
    }
};
