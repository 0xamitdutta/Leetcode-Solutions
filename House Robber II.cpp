class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        return max(helper(nums, 0, n-1), helper(nums, 1, n));
    }
    
  // Since every house is either robbed or not robbed and at least half of the houses are not robbed, the solution is simply the larger of two cases with consecutive houses.
  // We can pick any two consecutive houses. Here I picked House n not robbed and House 0 not robbed.
    int helper(vector<int>& nums, int start, int end){
        int n = nums.size();
        vector<int> dp(n);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for(int i = start+2; i < end; i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[end-1];
    }
};
