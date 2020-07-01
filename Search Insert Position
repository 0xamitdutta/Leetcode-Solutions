https://www.lintcode.com/problem/search-insert-position/description?source=post_page---------------------------

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            // Make sure that target lies in range
            if(nums[low] > target) return low;
            if(nums[high] < target) return high+1;
            
            // Now target is definitely within range
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
    }
};
