/*
Naive Approach : Run a DFS call from each cell and check if we are able to reach both oceans or not. TC: O(m*n)^2
Optimal Approach: Run a DFS from the border of the grid (Basically it means run a DFS from both oceans). TC: O(m*n)
*/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, 0));
        vector<vector<bool>> atlantic(m, vector<bool>(n, 0));
        
        // For top and bottom
        for(int j = 0; j < n; j++){
            dfs(matrix, 0, j, -1, pacific);
            dfs(matrix, m-1, j, -1, atlantic);
        }
        
        // For left and right
        for(int i = 0; i < m; i++){
            dfs(matrix, i, 0, -1, pacific);
            dfs(matrix, i, n-1, -1, atlantic);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
    
    //  Make dfs calls from the ocean instead of each cell.
    void dfs(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<bool>>& ocean){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
            return;
        if(matrix[i][j] < prev || ocean[i][j] == true)
            return;
        
        ocean[i][j] = true;
        dfs(matrix, i-1, j, matrix[i][j], ocean);
        dfs(matrix, i+1, j, matrix[i][j], ocean);
        dfs(matrix, i, j+1, matrix[i][j], ocean);
        dfs(matrix, i, j-1, matrix[i][j], ocean);
    }
};
