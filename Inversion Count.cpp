class Solution {
public:
    vector<int> twoSum(vector<int>& nums) {
        // Insert elements in a set and apply binary search for each num in nums
        set<int> s(nums.begin(), nums.end());
        int count = 0;
        for(int& num : nums){
          auto itr = s.upper_bound(num);
          count += distance(itr, s.end());
        }
        return count;
    }
};
