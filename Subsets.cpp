class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0){
            return {{}};
        }
        int num = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> rres = subsets(nums);
        
        vector<vector<int>> cres;
        for(auto& res : rres){
            cres.push_back(res); // We do not add num 
            
            res.insert(res.begin(), num); // We add num to res
            cres.push_back(res);
        }
        return cres;
    }
};

/*
Example: 1, 2, 3
For 2, 3 we have : [], [2], [3], [2, 3];

Then for every ans in 2, 3 we either add or do not add 1
[], [2], [3], [2, 3]
[1], [1, 2], [1, 3], [1, 2, 3]
*/
