class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i > 0 && nums[i-1] >= nums[i])
            i--;
        if(i > 0){
            int j = n-1;
            while(nums[i-1] >= nums[j])
                j--;
            swap(nums[i-1], nums[j]);
        }
        reverse(nums.begin()+i, nums.end());
    }
};

/*
            i-1  i j 
Example : 1 2    5 4 1
          1 4 5 2 1 (Swap i-1 and j)
          1 4 1 2 5 (Sort from i to end)
*/
