class Solution {
public:
    int dp[51][51][51][51];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return max(0, helper(grid, grid.size(), 0, 0, 0, 0));
    }
    
    // Traversing from n-1,n-1 is same as 0,0. 
    // In this way we don not have to think which cell have been taken previosly
    int helper(vector<vector<int>>& grid, int n, int r1, int c1, int r2, int c2){
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        // If we reach the last cell return its value(0 or 1)
        // Also r1,c1 and r2,c2 both reach at the same time. Hence n0 need to check for r2,c2
        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];
        if(dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];
        
        int cherries;
        // If both are at same cell count only once else count two times
        if(r1 == r2 && c1 == c2)
            cherries = grid[r1][c1];
        else
            cherries = grid[r1][c1] + grid[r2][c2];
        cherries += max(helper(grid, n, r1+1, c1, r2+1, c2), max(helper(grid, n, r1+1, c1, r2, c2+1), max(helper(grid, n, r1, c1+1, r2+1, c2), helper(grid, n, r1, c1+1, r2, c2+1))));
        return dp[r1][c1][r2][c2] = cherries;
    }
};
