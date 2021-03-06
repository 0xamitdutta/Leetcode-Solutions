class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<pair<int, int>> arr;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                if(A[i] == B[j]){
                    arr.push_back({i, j});
                }
            }
        }
        int n = arr.size();
        if(n == 0) return 0;
        sort(arr.begin(), arr.end());
        
        int ans = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j].first < arr[i].first && arr[j].second < arr[i].second){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
