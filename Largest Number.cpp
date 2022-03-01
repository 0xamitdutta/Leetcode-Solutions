class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        if(nums[0] == 0)
            return "0";
        string ans;
        for(int num : nums)
            ans += to_string(num);
        return ans;
    }
    
    static bool comp(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
};
