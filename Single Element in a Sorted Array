class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        /*** To check which way to go consider this:
        1. There will always be odd elements. Hence left and right element count will always be even or odd.
        2. Check if duplicate is in left or right. Further check if its even or odd.
        while(low < high){
            int mid = low + (high-low)/2;
            bool isEven = ((high-mid)%2 == 0);
            if(nums[mid] == nums[mid-1]){
                if(isEven)
                    high = mid-2;
                else
                    low = mid+1;
            }
            else if(nums[mid] == nums[mid+1]){
                if(isEven)
                    low = mid+2;
                else
                    high = mid-1;
            }
            else
                return nums[mid];
        }
        return nums[low];
    }
};
