// Line Sweep algorithm using prefix sum. Use binary search to find minimum queries
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0, high = queries.size();
        int res = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(isFeasible(nums, queries, mid)) {
                res = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }
        return res;
    }

    bool isFeasible(vector<int>& nums, vector<vector<int>>& queries, int& mid) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for(int i = 0; i < mid; i++) {
            vector<int> query = queries[i];
            prefix[query[0]] -= query[2];
            prefix[query[1] + 1] += query[2];
        }
        for(int i = 1; i < n; i++) 
            prefix[i] += prefix[i-1];
        for(int i = 0; i < n; i++) {
            if(nums[i] + prefix[i] > 0)
                return false;
        }
        return true;
    }
};
