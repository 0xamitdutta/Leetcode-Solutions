class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, vector<int>());
        return res;
    }
    
    void helper(vector<int> nums, vector<int> temp){
        if(nums.size() == 0){
            res.push_back(temp);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i]; // Take the character at the ith index
            vector<int> lpart, rpart;   // Find left and right part
            for(int j = 0; j < i; j++) 
                lpart.push_back(nums[j]);
            for(int j = i+1; j < nums.size(); j++)
                rpart.push_back(nums[j]);
            
            // Concatenate left and right part
            vector<int> rest_of_nums(lpart);
            rest_of_nums.insert(rest_of_nums.end(), rpart.begin(), rpart.end());
            
            // Pass the concatenated and the temp vector by adding current num in temp
            temp.push_back(num);
            helper(rest_of_nums, temp);
            temp.pop_back();
        }
    }
};

/*
Example : [1, 2, 3]
Take 1 pass [2, 3] -> 1,2,3 -> 1,3,2
Take 2 pass [1, 3] -> 2,1,3 -> 2,3,1
Take 3 pass [1, 2] -> 3,1,2 -> 3,2,1
*/
