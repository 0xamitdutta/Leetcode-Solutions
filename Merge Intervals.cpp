class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        res.push_back(nums[0]);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i][0] > res.back()[1]) res.push_back(nums[i]);    //Just think about 2 consecutive elements
            else res.back()[1] = max(res.back()[1], nums[i][1]);
        }
        return res;
    }
};
