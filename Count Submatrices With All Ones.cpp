// O(m*m*n)
class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        // Use the function to count ones for 1D array and expand to 2D array
        // From the current row we are trying to go as below as possible. That's why we are using the AND operation
        for(int i = 0; i < m; i++) {
            vector<int> A(n, 1);
            for(int j = i; j < m; j++) {
                for(int k = 0; k < n; k++) {
                    A[k] &= matrix[j][k];
                }
                res += countOnes(A);
            }
        }
        return res;
    }
    
    // Function to count ones in a 1D array
    int countOnes(vector<int>& A) {
        int res = 0, len = 0;
        for(int i = 0; i < A.size(); i++) {
            len = (A[i] == 0 ? 0 : len + 1);
            res += len;
        }
        return res;
    }
};
