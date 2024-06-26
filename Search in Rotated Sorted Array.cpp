class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums, target);
       
        int left = search(nums, target, 0, pivot-1);
        int right = search(nums, target, pivot, n-1);
        if(left == -1 && right == -1)
            return -1;
        return max(left, right);
    }
    
    int findPivot(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[high])
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
    
    int search(vector<int>& nums, int target, int low, int high){
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid])
                low = mid+1;
            else 
                high = mid-1;
        }
        return -1;
    }
};
