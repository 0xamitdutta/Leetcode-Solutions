class Solution {
    public:
    int findPages(int A[], int N, int M) {
        if(N < M) return -1;
        
        int sum = 0;
        for(int i = 0; i < N; i++) sum += A[i];
        int low = A[0], high = sum;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(A, N, M, mid)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
    
    bool isPossible(int A[], int N, int M, int mid) {
        int students = 1;
        int sum = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] > mid) return false;
            if(sum + A[i] > mid) {
                students++;
                sum = A[i];
                if(students > M) return false;
            } else
                sum += A[i];
        }
        return true;
    }
};
