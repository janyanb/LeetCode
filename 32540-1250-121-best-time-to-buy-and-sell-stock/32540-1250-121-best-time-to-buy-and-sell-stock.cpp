class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int left = 0, right = left +1 ;
        while(left < prices.size() && right < prices.size()){
            if (prices[left] > prices[right]){
                left ++;
            } else {
                maxProfit = max(prices[right] - prices[left], maxProfit);
                right++;
            }
        };
        return maxProfit;
    }
};
