class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Keep track of the minPrice and profit at each index of the array
        int minP = prices[0], profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            minP = min(minP, prices[i]);
            profit = max(profit, prices[i] - minP);
        }
        return profit;
    }
};
