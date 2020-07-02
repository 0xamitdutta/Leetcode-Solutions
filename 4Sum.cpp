class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 4)
            return res;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int b = nums[j];
                
                int low = j+1, high = n-1;
                while(low < high){
                    int c = nums[low], d = nums[high];
                    if(a + b + c + d == target){
                        res.push_back({a, b, c, d});
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        low++; high--;
                    }
                    else if(a + b + c + d < target)
                        low++;
                    else
                        high--;
                }
            }
        }
        return res;
    }
};
