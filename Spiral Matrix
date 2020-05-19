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
            for(int j = c1; j <= c2; j++)
                res.push_back(matrix[r1][j]);
            r1++;
            
            for(int i = r1; i <= r2; i++)
                res.push_back(matrix[i][c2]);
            c2--;
            
            // The if condition is there when r1 == r2. In such case after the above 2 for loops the while loop is violated.
            if(r1 <= r2){
                for(int j = c2; j >= c1; j--)
                    res.push_back(matrix[r2][j]);
            }
            r2--;
            
            // The if condition is there when r1 == r2. In such case after the above 2 for loops the while loop is violated.
            if(c1 <= c2){
                for(int i = r2; i >= r1; i--)
                    res.push_back(matrix[i][c1]);
            }
            c1++;
        }
        return res;
    }
};
