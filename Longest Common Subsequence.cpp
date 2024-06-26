/*
Recurrence Relation:
LCS(A, B, m, n) = LCS(A, B, m-1, n-1) + 1 if A[m-1] == B[n-1]
LCS(A, B, m, m) = max( LCS(A, B, m-1, n), LCS(A, B, m, n-1) ) if A[m-1] != B[m-1]
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int dp[m+1][n+1];
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
};
