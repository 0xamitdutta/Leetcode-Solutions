class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;        // Stores index
        
        for(int i = 0; i < n; i++){
            // Remove numbers that are out of range k
            if(!dq.empty() && dq.front() < i-k+1)
                dq.pop_front();
            // Remove smaller numbers in within range k as they are useless.
            // Eg: 10, 20, 30 -> (1) Insert 10 (2) Remove 10, Insert 20, (3) Remove 20, Insert 30. This way maximum element is always at front.
            while(!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);
            if(i-k +1 >= 0)   // Push into result vector if window size >= k. i.e (i+1) - k >= 0
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
