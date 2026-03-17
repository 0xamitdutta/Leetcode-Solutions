// Best explanation: https://leetcode.com/problems/find-a-peak-element-ii/solutions/1276556/javapythonc-clear-explanation-with-image-au16/
/*
1. Get the max element from each column
2. Do Peak Element I on each of those values
3. But we don't need max element from each column, otherwise it would be m*n
4. Take only midCol and disregard the left or right half. So binary search on the columns
*/

// O(m * logn)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = n-1;
        while(low <= high) {
            int midCol = low + (high-low)/2;
            int maxRow = 0;

            for(int i = 0; i < m; i++) {
                if(mat[i][midCol] > mat[maxRow][midCol])
                    maxRow = i;
            }
            bool isLeftBigger = midCol - 1 >= 0 && mat[maxRow][midCol-1] > mat[maxRow][midCol];
            bool isRightBigger = midCol + 1 < n && mat[maxRow][midCol+1] > mat[maxRow][midCol];
            if(!isLeftBigger && !isRightBigger)
                return {maxRow, midCol};
            else if(isLeftBigger) 
                high = midCol - 1;
            else
                low = midCol + 1;
        }
        return {-1, -1};
    }
};
