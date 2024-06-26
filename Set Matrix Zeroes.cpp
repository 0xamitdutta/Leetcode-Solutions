// Space : O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        
        vector<bool> row(m), col(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

// Space : O(1)
/* Brace Yourselves. This solution is a bumpy ride*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        
        // Check if the first row has any 0
        bool isFirst = false;
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0)
                isFirst = true;
        }
        
        // For any element with 0 value make the 1st row with corresponding col as 0
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0)
                    matrix[0][j] = 0;
            }
        }
        
        // Iterate from 2nd row because 1st row has vital details due to previous for loop.
        for(int i = 1; i < m; i++){
            bool isZero = false;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    isZero = true;
                    break;
                }
            }
            // After every row check whether that row has 0 or any element wwith matrix[0][j] is 0
            for(int j = 0; j < n; j++){
                if(isZero || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        // Finally if first row is 0 make it 0
        if(isFirst){
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
    }
};
