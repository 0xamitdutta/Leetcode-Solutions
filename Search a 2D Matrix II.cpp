// Time Complexity : O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        
        int i, j = n-1;
        for(i = 0; i < m; i++){
            while(j > 0 && matrix[i][j] > target)
                j--;
            if(matrix[i][j] == target)
                return true;
        }
        return false;
    }
};
