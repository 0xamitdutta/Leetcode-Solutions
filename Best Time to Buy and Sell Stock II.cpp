class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Visualise the valleys and peaks. If you buy a stock at a point x just sell it immediately for a peak higher than x
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};
