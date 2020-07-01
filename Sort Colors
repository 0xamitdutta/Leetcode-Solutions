class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int i = 0;
        while(i < n){
            // Only one step as all no. before nums[i] is 0 or 1
            if(nums[i] == 0){
                swap(nums[i], nums[low]);
                i++;
                low++;
            }
            
            // Maybe a 2 step process cuz after swapping nums[i] may become 0
            else if(nums[i] == 2 && i < high){
                swap(nums[i], nums[high]);
                high--;
            }
            else
                i++;
        }
    }
};
