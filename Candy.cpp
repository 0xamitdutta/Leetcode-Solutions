class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> res(n, 1);
        // Comparing with left neighbours
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1])
                res[i] = res[i-1] + 1;
        }
        // Comparing with right neighbours
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1])
                res[i] = max(res[i], res[i+1] + 1);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += res[i];
        return ans;
    }
};
