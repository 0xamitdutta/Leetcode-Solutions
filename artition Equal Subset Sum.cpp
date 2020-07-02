class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return false;
        
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];
        if(sum & 1)
            return false;
        
        sum /= 2;
        int dp[n+1][sum+1];
        for(int j = 0; j <= sum; j++)
            dp[0][j]= false;
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};
