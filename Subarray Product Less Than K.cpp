class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int ans = 0, i, j = 0, prod = 1;
        for(i = 0; i < n; i++) {
            prod *= nums[i];
            while(prod >= k) {
                prod /= nums[j];
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};
