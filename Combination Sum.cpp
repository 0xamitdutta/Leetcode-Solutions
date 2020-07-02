// Time : O(n^target)
// Space : O(target)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        getSum(res, curr, nums, target, 0);
        return res;
    }
    
    void getSum(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int target, int index){
        if(target < 0)
            return;
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            curr.push_back(nums[i]);
            getSum(res, curr, nums, target-nums[i], i);
            curr.pop_back();
        }
    }
};
