class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }
        for(int d = 1; d < n; d++){
            for(int i = 0; i < n-d; i++){
                dp[i][i+d] = max(nums[i] - dp[i+1][i+d], nums[i+d] - dp[i][i+d-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};
