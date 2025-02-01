// Time : O(n^target)
// Space : O(target)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        combinationSumHelper(nums, target, 0, {}, res);
        return res;
    }

    void combinationSumHelper(vector<int>& nums, int target, int index, vector<int> curr, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        if(target < 0) 
            return;
        for(int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            combinationSumHelper(nums, target - nums[i], i, curr, res);
            curr.pop_back();
        }
    }
};
