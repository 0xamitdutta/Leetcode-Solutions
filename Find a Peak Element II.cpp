class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        int low = 0, high = n-1;
        while(low <= high) {
            int midcol = low + (high-low)/2;
            int maxrow = 0;
            for(int i = 0; i < m; i++) {
                maxrow = mat[i][midcol] > mat[maxrow][midcol] ? i : maxrow; 
            }
            bool isLeft = midcol-1 >= 0 && mat[maxrow][midcol-1] > mat[maxrow][midcol];
            bool isRight = midcol+1 < n && mat[maxrow][midcol+1] > mat[maxrow][midcol];
            if(!isLeft && !isRight) 
                return {maxrow, midcol};
            else if(isLeft)
                high = midcol-1;
            else
                low = midcol+1;
        }
        return {};
    }
};
