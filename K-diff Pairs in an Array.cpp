class Solution {
public:
    int findPairs(vector<int>& nums, int K) {
        int n = nums.size();
        if(n == 0 || K < 0) return 0;
        
        unordered_map<int, int> hash;
        for(int num : nums) {
            hash[num]++;
        }
        int count = 0;
        // Check for 2 cases. K == 0 and K != 0
        for(auto [key, val] : hash) {
            if((!K && val > 1) || (K && hash.count(key + K)))
                count++;
        }
        return count;
    }
};
