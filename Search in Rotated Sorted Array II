class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low);
            if(nums[mid] == target)
                return true;
            
            // Search in the right half
            if(nums[mid] < nums[high]){
                if(target > nums[mid] && target <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
            
            // Search in the left half
            else if(nums[mid] > nums[low]){
                if(target >= nums[low] && target < nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            
            //Don't forget to check left and right boundary **EXTRA**
            else{
                if(nums[mid] == nums[low]) low++;
                if(nums[mid] == nums[high]) high--;
            }
        }
        return false;
    }
};
