class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // Check for 2 trivial cases
        if(n == 1) return nums[0];
        if(nums[0] < nums[n-1]) return nums[0];
        
        int low = 0, high = nums.size()-1;
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};
