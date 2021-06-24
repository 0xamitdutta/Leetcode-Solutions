// O(n*n * log(k))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                pq.push(matrix[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};

// O(2n * log(max_val))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Binary Search can be applied either on 1. Index based OR 2. Range based
        // We apply it on range here cuz the search space is not monotonically increasing/decreasing
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low < high) {
            int mid = low + (high-low)/2;
            // Count the no. of elements <= mid
            int count = 0, j = n-1;
            for(int i = 0; i < n; i++) {
                while(j >= 0 && matrix[i][j] > mid)
                    j--;
                count += j + 1;
            }
            if(count < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
