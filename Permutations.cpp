class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteHelper(nums, {}, res);
        return res;
    }

    void permuteHelper(vector<int> nums, vector<int> curr, vector<vector<int>>& res) {
        if(nums.size() == 0) {
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            curr.push_back(num);
            vector<int> remaining;
            for(int j = 0; j < i; j++) remaining.push_back(nums[j]);
            for(int j = i+1; j < nums.size(); j++) remaining.push_back(nums[j]);
            permuteHelper(remaining, curr, res);
            curr.pop_back();
        }
    }
};
