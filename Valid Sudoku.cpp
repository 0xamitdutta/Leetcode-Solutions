class Solution {
public:
    int row[9][9] = {0}; // row[3][4] = row 4 and num 5
    int col[9][9] = {0}; // col[1][2] = col 2 and num 3
    int block[3][3][9] = {0};
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    if(row[i][num] || col[j][num] || block[i/3][j/3][num]) return false;
                    row[i][num]++; col[j][num]++; block[i/3][j/3][num]++;
                }
            }
        }
        return true;
    }
};
