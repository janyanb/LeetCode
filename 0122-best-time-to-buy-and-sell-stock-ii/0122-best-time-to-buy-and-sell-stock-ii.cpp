class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        int right = 1;
        while(right< prices.size()){
            if(prices[right] > prices[right - 1]){
                totalProfit += prices[right] - prices[right - 1]; 
            }
            right++;
        }

        return totalProfit;
    }
};