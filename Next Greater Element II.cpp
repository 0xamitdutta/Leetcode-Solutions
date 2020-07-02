class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, -1);
        stack<int> s;
        for(int i = 0; i < 2*n; i++){
            while(!s.empty() && nums[s.top()] < nums[i%n]){
                v[s.top()] = nums[i%n];
                s.pop();
            }
            if(i < n)
                s.push(i);
        }
        return v;
    }
};
