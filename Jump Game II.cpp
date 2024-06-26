class Solution {
public:
    // This is a BFS Solution where every level has nodes = curr_max
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        
        int level = 0;
        int curr_max = 0, i = 0;
        while(i <= curr_max){
            level++;
            int furthest = curr_max;
            for(; i <= furthest; i++){
                curr_max = max(curr_max, i+nums[i]);
                if(curr_max >= n-1)
                    return level;
            }
        }
        return -1;
    }
};
