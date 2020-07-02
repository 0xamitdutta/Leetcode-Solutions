class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m == 0) return false;
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index){
        if(index == word.size())
            return true;
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[index])
            return false;
        
        char temp = board[i][j];
        board[i][j] = ' ';
        bool found = dfs(board, word, i-1, j, index+1) || dfs(board, word, i+1, j, index+1) || dfs(board, word, i, j+1, index+1) || dfs(board, word, i, j-1, index+1);
        board[i][j] = temp;
        return found;
    }
};
