class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size();
        int col = board[0].size();
        set<string> temp;
        
        for(string& word : words){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                        temp.insert(word);
                }
            }
        }
        vector<string> res(temp.begin(), temp.end());
        return res;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int len){
        if(len == word.size())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[len])
            return false;
        char temp = board[i][j];
        board[i][j] = ' ';
        bool found = dfs(board, word, i, j+1, len + 1) ||  
            dfs(board, word, i, j-1, len + 1) || 
            dfs(board, word, i+1, j, len + 1) || 
            dfs(board, word, i-1, j, len + 1);
        
        board[i][j] = temp;
        return found;
    }
};
