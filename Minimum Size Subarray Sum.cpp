class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int i = 0, j = 0;
        int sum = 0, len = INT_MAX;
        while(j < n){
            sum += nums[j];
            j++;
            while(sum >= s){
                len = min(len, j-i);
                sum -= nums[i];
                i++;
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
