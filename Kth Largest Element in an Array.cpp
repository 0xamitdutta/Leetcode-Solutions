// You can sort or use a min heap which are 2 basic solutions

// Using quickselect
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0, high = nums.size()-1;
        k = nums.size() - k + 1;
        while(low <= high){
            int pivot = partition(nums, low, high);
            if(pivot == k-1){
                return nums[pivot];
            }
            else if(pivot > k-1){
                high = pivot - 1;
            }
            else{
                low = pivot + 1;
            }
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int low, int high){
        int x = nums[high];
        int i = low;
        for(int j = low; j <= high; j++){
            if(nums[j] < x){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
};

// Using randomised quickselect
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0, high = nums.size()-1;
        k = nums.size() - k + 1;
        while(low <= high){
            int pivot = partition(nums, low, high);
            if(pivot == k-1){
                return nums[pivot];
            }
            else if(pivot > k-1){
                high = pivot - 1;
            }
            else{
                low = pivot + 1;
            }
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int low, int high){
        int r = rand() % (high-low+1);
        swap(nums[low+r], nums[high]);
        
        int x = nums[high];
        int i = low;
        for(int j = low; j <= high; j++){
            if(nums[j] < x){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
};
