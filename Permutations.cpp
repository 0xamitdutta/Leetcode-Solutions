class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> vis(nums.size(), false);
        permutations(nums, res, curr, vis);
        return res;
    }
    
    void permutations(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, vector<bool>& vis){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(vis[i]) continue;
            vis[i] = true;
            curr.push_back(nums[i]);
            permutations(nums, res, curr, vis);
            curr.pop_back();
            vis[i] = false;
        }
    }
};
