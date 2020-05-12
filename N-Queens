class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n, string(n, '.'));
        nQueens(res, curr, 0, n);
        return res;
    }
    
    void nQueens(vector<vector<string>>& res, vector<string>& curr, int row, int& n){
        if(row == n) {
            res.push_back(curr);
            return;
        }
        
        // Traverse each column for untill a position is found in that row
        for (int col = 0; col != n; ++col){
            if (isValid(curr, row, col, n)) {
                curr[row][col] = 'Q';
                nQueens(res, curr, row + 1, n);
                curr[row][col] = '.';
            }
        }
    }
    
    bool isValid(std::vector<std::string> &curr, int row, int col, int &n) {
        // Check for all rows from 0 to row-1 of the same column
        for (int i = 0; i < row; i++){
            if (curr[i][col] == 'Q')
                return false;
        }
        
        // Check for diag1 at 135degree
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if (curr[i][j] == 'Q')
                return false;
        }
        
        // Check for diag2 at 45degree
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if (curr[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
