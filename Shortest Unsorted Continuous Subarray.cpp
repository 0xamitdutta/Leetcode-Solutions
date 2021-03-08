// O(n^2)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = INT_MAX, r = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[j] < nums[i]){
                    l = min(l, i);
                    r = max(r, j);
                }
            }
        }
        return r < l ? 0 : r-l+1;
    }
};

// O(nlogn)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        
        int l = INT_MAX, r = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != sorted_nums[i]){
                if(l == -1){
                    l = i;
                }
                else{
                    r = i;
                }
            }
        }
        return r < l ? 0 : r-l+1;
    }
};

// O(n), O(n) Space
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stk;
        int l = INT_MAX, r = 0;
        for(int i = 0; i < nums.size(); i++){
            while(!stk.empty() && nums[i] < nums[stk.top()]){
                l = min(l, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        
        while(!stk.empty()){
            stk.pop();
        }
        for(int i = nums.size()-1; i >= 0; i--){
            while(!stk.empty() && nums[i] > nums[stk.top()]){
                r = max(r, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        return r < l ? 0 : r-l+1;
    }
};

// O(n), O(1) Space
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minm = INT_MAX, maxm = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                minm = min(minm, nums[i]);
            }
        }
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] > nums[i+1]){
                maxm = max(maxm, nums[i]);  
            }
        }
        
        int l, r;
        for(l = 0; l < nums.size(); l++){
            if(nums[l] > minm)
                break;
        }
        for(r = nums.size()-1; r >= 0; r--){
            if(nums[r] < maxm)
                break;
        }
        return r < l ? 0 : r-l+1;
    }
};
