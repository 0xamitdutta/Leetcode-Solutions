class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, count = 0;
        for(int& num : nums){
            sum += num;
            if(m.find(sum-k) != m.end())
                count += m[sum-k];
            m[sum] += 1;
        }
        return count;
    }
};