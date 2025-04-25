class Solution {
    const int INF = 1e9; 
public:
    int findComb(vector<int>& nums, int amount, int ind, long long total, vector<vector<int>>& dp){
        if(amount == total) return 0;
        if(total > amount) return INF;
        if(ind == nums.size()) return INF;

        if (dp[ind][total] != -1) return dp[ind][total];          //counts how mant more min num of coins needed at state[0][10] = 1

        int pick = 1 + findComb(nums, amount, ind, total + nums[ind], dp);
        int notPick = findComb(nums, amount, ind + 1, total, dp);

        return dp[ind][total] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {

        long long total = 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount +1, -1));
        int res = findComb(coins, amount, 0, total, dp);

        return (res != INF)? res : -1;
    }
};