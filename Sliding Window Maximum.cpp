class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1);
        deque<int> deq;
        // Store index
        for(int i = 0; i < n; i++){
            // Remove numbers out of range k
            if(!deq.empty() && deq.front() < i-k+1)
                deq.pop_front();
            // Remove smaller numbers in k range as they are useless
            while(!deq.empty() && nums[i] > nums[deq.back()])
                deq.pop_back();
            deq.push_back(i);
            if(i-k+1 >= 0)
                res[i-k+1] = nums[deq.front()];
        }
        return res;
    }
};
