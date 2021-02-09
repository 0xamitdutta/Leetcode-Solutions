// If the interviewer allows lower bound and upper bound
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();        
        vector<int> res(2, -1);
        
        int left  = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        right--;
        if(left <= n-1 && nums[left] == target) res[0] = left;
        if(right >= 0 && nums[right] == target) res[1] = right;
        return res;
    }
};

// If the interviewer tells you to write the lower bound and upper bound function
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(2, -1);
        int l = searchLeft(nums, target);
        int r = searchRight(nums, target);
        res[0] = l, res[1] = r;
        return res;
    }
    
    int searchLeft(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int first = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid-1;
            }
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return first;
        
    }
    int searchRight(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int last = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid+1;
            }
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return last;
    }
};
