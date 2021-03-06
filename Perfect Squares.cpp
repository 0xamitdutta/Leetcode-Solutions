class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        // dp[i] represents min no. of perfect squares for i
        for(int i = 1; i <= n; i++){
            // Remove j*j from i. similar to LIS 
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};
