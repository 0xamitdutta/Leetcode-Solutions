class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        // dp[i][j] stores the largest no. of stones you collect more than your opponent from piles i to j
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        // You collect all stones from i to i
        for(int i = 0; i < n; i++){
            dp[i][i] = piles[i];
        }
        /*
        For a pile from i to j. Let the distance is d
        Then dp[i][j] = max(Select i - Opp. selects the best from i+1 to j, Select j - Opp. selects  the best from i to j-1.
        */
        
        // Filling dp matrix in diagonal manner. Keep increasing gap and reducing bottom rows
        for(int d = 1; d < n; d++){
            for(int i = 0; i < n-d; i++){
                dp[i][i+d] = max(piles[i] - dp[i+1][i+d], piles[i+d] - dp[i][i+d-1]);
            }
        }
        return dp[0][n-1];
    }
};
