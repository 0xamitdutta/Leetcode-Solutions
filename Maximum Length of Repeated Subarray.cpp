class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int dp[m+1][n+1];
        int max_len = 0;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(A[i-1] == B[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    max_len = max(max_len, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return max_len;
    }
};
