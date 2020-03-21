class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ind; 
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            int comp = target - nums[i];
            if(m.find(comp) != m.end()){
                ind.push_back(i);
                ind.push_back(m[comp]);
                return ind;
            }
            m[nums[i]] = i;
        }    
        return ind;
    }
};
