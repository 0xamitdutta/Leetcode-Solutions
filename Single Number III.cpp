class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xy = 0;
        for(int num : nums)
            xy ^= num;
        
        xy &= -xy; // Get the last set bit
        // Eg : n = 10110. Then (n & -n) = 00010
        
        vector<int> res = {0, 0}; // Divide nums into 2 groups
        for(int num : nums){
            if(num & xy)
                res[1] ^= num;
            else
                res[0] ^= num;
        }
        return res;
    }
};
