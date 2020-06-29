class Solution {
public:
    // If -ve count == even. Both loops return the same result
    // If -ve count == odd. Result is max(first loop, second loop)
    int maxProduct(vector<int>& nums) {
        int curr_product = 1, max_product = INT_MIN;
        
        // The first loop discards the last -ve no. for odd count
        for(int i = 0; i < nums.size(); i++){
            curr_product *= nums[i];
            if(curr_product > max_product)
                max_product = curr_product;
            if(curr_product == 0)
                curr_product = 1;
        }
        // The second loop discards the first -ve no. for odd count
        curr_product = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            curr_product *= nums[i];
            if(curr_product > max_product)
                max_product = curr_product;
            if(curr_product == 0)
                curr_product = 1;
        }
        return max_product;
    }
};
