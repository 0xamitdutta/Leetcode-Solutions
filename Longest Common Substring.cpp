/*
Recurrence Relation:
LCS(A, B, m, n) = LCS(A, B, m-1, n-1) + 1 if A[m-1] == B[n-1]
LCS(A, B, m, m) = 0 if A[m-1] != B[m-1]
*/

class Solution {
public:
    int findLength(string& A, string& B) {
        int m = A.size();
        int n = B.size();
        
        int ans = 0;
        int dp[m+1][n+1];
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
