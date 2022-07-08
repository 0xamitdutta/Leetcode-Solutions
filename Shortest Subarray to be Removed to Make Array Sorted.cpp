class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;
        while(l < r && arr[l] <= arr[l+1]) l++; // Eliminate the right side i.e n-l-1
        if(l == n-1) return 0;
        
        while(r > l && arr[r-1] <= arr[r]) r--; // Eliminate the left side i.e r
        
        int ans = min(r, n-l-1), i = 0, j = r; // Answer is at most min(r, n-l-1). Now try to shrink window by eliminating middle elements 
        while(i <= l && j < n){
            if(arr[i] <= arr[j]) {
                ans = min(ans, j-i-1);
                i++;
            } else
                j++;
        }
        return ans;
    }
};
