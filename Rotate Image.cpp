class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        
        // Transpose
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        
        // Swapping n/2 columns
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++)
                swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }
};
