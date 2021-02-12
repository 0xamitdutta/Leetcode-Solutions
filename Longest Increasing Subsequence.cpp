class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int dp[n]; // dp(i) contains longest Increasing Subsequence ending at the index i
        int max_len = 1;
        for(int i = 0; i < n; i++)
            dp[i] = 1;
        for(int i = 1; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
