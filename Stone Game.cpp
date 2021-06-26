class Solution {
public:
    int dp[501][501][2];
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return helper(0, piles.size()-1, piles, 1);
    }
    
    int helper(int l, int r, vector<int>& piles, int ID) {
        if(r < l) return 0;
        if(dp[l][r][ID] != -1) return dp[l][r][ID];
        
        int next = ID ^ 1;
        int score = 0;
        if(ID == 1) {
            dp[l][r][1] = max(piles[l] + helper(l+1, r, piles, next), piles[r] + helper(l, r-1, piles, next));
        }
        else {
            dp[l][r][0] = min(-piles[l] + helper(l+1, r, piles, next), -piles[r] + helper(l, r-1, piles, next));
        }
        return dp[l][r][ID];
    }
};
