class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int r1 = 0, r2 = n-1, c1 = 0, c2 = n-1;

        int val = 1;
        while(r1 <= r2 && c1 <= c2) {
            // Right
            for(int i = c1; i <= c2; i++)
                res[r1][i] = val++;
            r1++;
            // Down
            for(int i = r1; i <= r2; i++) 
                res[i][c2] = val++;
            c2--;

            if(r1 > r2 || c1 > c2) return res;

            // Left
            for(int i = c2; i >= c1; i--) 
                res[r2][i] = val++;
            r2--;

            // Top
            for(int i = r2; i >= r1; i--)
                res[i][c1] = val++;
            c1++;
        }
        return res;
    }
};
