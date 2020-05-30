class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0, n = nums.size();
        for(int num : nums)
            sum += num;
        if(sum < S || (sum+S)&1)
            return 0;
        
        int s1 = (sum+S)/2;
        int dp[n+1][s1+1];
        for(int i = 0; i <= s1; i++)
            dp[0][i] = 0;
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= s1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s1];
    }
};
