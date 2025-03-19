class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;

        // Iterate through the prices array
        for (int i = 1; i < prices.size(); i++) {
            // Add the positive difference between consecutive days
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }

        return totalProfit;
    }
};