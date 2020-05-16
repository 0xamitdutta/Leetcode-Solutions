class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Just keep track of min_price and check whether prices[i] - min_price > profit
        int min_price = INT_MAX, profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < min_price)
                min_price = prices[i];
            else if(prices[i] - min_price > profit)
                profit = prices[i] - min_price;
        }
        return profit;
    }
};
