class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        if(n == 0) return A[0];
        
        int sum = A[0];
        int curr_max = A[0], total_max = A[0];
        int curr_min = A[0], total_min = A[0];
        for(int i = 1; i < A.size(); i++){
            curr_max = max(A[i]+curr_max, A[i]);
            total_max = max(total_max, curr_max);
            curr_min = min(A[i]+curr_min, A[i]);
            total_min = min(total_min, curr_min);
            sum += A[i];
        }
        return total_max > 0 ? max(total_max, sum-total_min) : total_max;
    }
};
