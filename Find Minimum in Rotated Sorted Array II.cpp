class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // Check for 2 trivial cased
        if(n == 1) return nums[0];
        if(nums[0] < nums[n-1]) return nums[0];
        
        // Exactly similar to Find Minimum in Rotated Sorted Array I. Just check all 3 cases for nums[mid] with nums[high]
        int low = 0, high = n-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[high])
                high = mid;
            else if(nums[mid] > nums[high])
                low = mid+1;
            else
                high--;
        }
        return nums[low];
    }
};
