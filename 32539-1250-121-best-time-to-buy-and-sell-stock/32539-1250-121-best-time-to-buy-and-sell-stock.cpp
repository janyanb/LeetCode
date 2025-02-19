class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX; 
        int max_profit = 0;
        
        for (int price : prices) {
            // Update the minimum price so far.
            if (price < min_price) {
                min_price = price;
            }
            // Calculate potential profit at the current price.
            int profit = price - min_price;
            // Update maximum profit if the current profit is higher.
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
        
        return max_profit;
    }
};
