class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        
        int r1 = 0;
        int r2 = matrix.size()-1;
        int c1 = 0;
        int c2 = matrix[0].size() - 1;
        while(r1 <= r2 && c1 <= c2){
            // Right
            for(int j = c1; j <= c2; j++)
                res.push_back(matrix[r1][j]);
            r1++;

            // Down
            for(int i = r1; i <= r2; i++)
                res.push_back(matrix[i][c2]);
            c2--;
            
            if(r1 > r2 || c1 > c2) break;

            // Left
            for(int j = c2; j >= c1; j--)
                res.push_back(matrix[r2][j]);
            r2--;

            // Top
            for(int i = r2; i >= r1; i--)
                res.push_back(matrix[i][c1]);
            c1++;
        }
        return res;
    }
};

// 1 for loop instead of 4
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> traverseCount = {n, m-1};
        
        int ir = 0, ic = -1;
        int idir = 0;
        vector<int> res;
        while(res.size() < m*n) {
            for(int i = 0; i < traverseCount[idir % 2]; i++) {
                ir += dirs[idir][0], ic += dirs[idir][1];
                res.push_back(matrix[ir][ic]);
            }
            traverseCount[idir % 2]--;
            idir = (idir + 1) % 4;
        }
        return res;
    }
};
