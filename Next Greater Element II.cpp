class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> A;
        // Best way for handling circular array is to create new array and store all elements twice
        for(int i = 0; i < 2*n; i++) A.push_back(nums[i % n]);
        
        // Stack is storing the indexes instead of values which is helpful
        stack<int> s;
        vector<int> res(n, -1);
        for(int i = 0; i < A.size(); i++) {
            while(!s.empty() && A[i] > A[s.top()]) {
                res[s.top()] = A[i];
                s.pop();
            }
            if(i < n)
                s.push(i);
        }
        return res;
    }
};
