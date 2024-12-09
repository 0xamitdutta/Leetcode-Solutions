class Solution {
public:
    int dp[301][5001];
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        int ans = fun(coins, 0, amount);
        return ans;
    }

    int fun(vector<int>& coins, int i, int amount) {
        if(amount == 0)
            return 1;
        if(i >= coins.size()) 
            return 0;
        if(dp[i][amount] != -1)
            return dp[i][amount];
        int ans = fun(coins, i+1, amount);
        if(coins[i] <= amount)
            ans += fun(coins, i, amount - coins[i]);
        return dp[i][amount] = ans;
    }
};
