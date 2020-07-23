class Solution {
public:
    int row[9][9];
    int col[9][9];
    int block[3][3][9];
    void solveSudoku(vector<vector<char>>& board) {
        // Hash all the numbers first
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    row[i][num] = 1; col[j][num] = 1; block[i/3][j/3][num] = 1;
                }
            }
        }
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int i, int j){
        if(i == 9) return true; // If all rows are completed means all is fine.
        if(j == 9) return solve(board, i+1, 0); // If all cols are completed go to next row
        if(board[i][j] != '.') return solve(board, i, j+1);
        
        for(char c = '1'; c <= '9'; c++){ // For current cell choose all 9 options
            int num = c - '1';
            if(feasible(board, i, j, num)){
                board[i][j] = c;
                row[i][num] = 1; col[j][num] = 1; block[i/3][j/3][num] = 1;
                if(solve(board, i, j+1))
                    return true;
                board[i][j] = '.';
                row[i][num] = 0; col[j][num] = 0; block[i/3][j/3][num] = 0;
            }
        }
        return false;
    }
    
    bool feasible(vector<vector<char>>& board, int i, int j, int num){
        if(row[i][num]) return false;
        if(col[j][num]) return false;
        if(block[i/3][j/3][num]) return false;
        return true;
    }
};
