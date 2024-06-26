class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        
        int last = n-1;
        for(int i = n-2; i >= 0; i--){
            if(i+nums[i] >= last)
                last = i;
        }
        return last == 0 ? true : false;
    }
};
