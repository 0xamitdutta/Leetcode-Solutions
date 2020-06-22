class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, curr_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            curr_sum += nums[i];
            if(curr_sum > max_sum)
                max_sum = curr_sum;
            if(curr_sum < 0)
                curr_sum = 0;
        }
        return max_sum;
    }
};

// In case you want the starting and ending index
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, curr_sum = 0;
        int start = 0, end = 0, s = 0;
        for(int i = 0; i < nums.size(); i++){
            curr_sum += nums[i];
            if(curr_sum > max_sum){
                max_sum = curr_sum;
                start = s;
                end = i;
            }
            if(curr_sum < 0){
                curr_sum = 0;
                s = i+1;
            }
        }
        cout << start << " " << end << endl;
        return max_sum;
    }
};
