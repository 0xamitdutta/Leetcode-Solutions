// You can sort or use a min heap which are 2 basic solutions

// Using quickselect
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k+1;
        return quickselect(nums, 0, nums.size()-1, k);
    }
    
    int quickselect(vector<int>& nums, int low, int high, int k){
        int pivot = partition(nums, low, high);
        if(pivot-low+1 < k)
            return quickselect(nums, pivot+1, high, k-pivot-1+low);
        if(pivot-low+1 > k)
            return quickselect(nums, low, pivot-1, k);
        if(pivot-low+1 == k)
            return nums[pivot];
        return -1;
    }
    
    int partition(vector<int>& nums, int low, int high){
        int x = nums[high];
        int i = low;
        for(int j = low; j < high; j++){
            if(nums[j] <= x){
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
        k = nums.size()-k+1;
        return quickselect(nums, 0, nums.size()-1, k);
    }
    
    int quickselect(vector<int>& nums, int low, int high, int k){
        int pivot = rand_partition(nums, low, high);
        if(pivot-low+1 < k)
            return quickselect(nums, pivot+1, high, k-pivot-1+low);
        if(pivot-low+1 > k)
            return quickselect(nums, low, pivot-1, k);
        if(pivot-low+1 == k)
            return nums[pivot];
        return -1;
    }
    
    int rand_partition(vector<int>& nums, int low, int high){
        int n = high-low+1;
        int x = rand() % n;
        swap(nums[low+x], nums[high]);
        return partition(nums, low, high);
    }
    
    int partition(vector<int>& nums, int low, int high){
        int x = nums[high];
        int i = low;
        for(int j = low; j < high; j++){
            if(nums[j] <= x){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
};
