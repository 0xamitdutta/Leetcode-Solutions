class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose : Mirror around the diagonal axis
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) 
                swap(matrix[i][j], matrix[j][i]);
        }
        // Swap Columns : Mirror around the vertical axis
        int i = 0, j = n-1;
        while(i < j) {
            for(int row = 0; row < n; row++)
                swap(matrix[row][i], matrix[row][j]);
            i++;
            j--;
        }
    }
};
