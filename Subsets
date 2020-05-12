class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, res, curr, 0);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int index){
        res.push_back(curr);
        for(int i = index; i < nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(nums, res, curr, i+1);
            curr.pop_back();
        }
    }
};
