class Solution {
public:
    int canRob(int i, vector<int>& nums, vector<int> &dp, int end){
        if(i < end || i< 0) return 0;
        if(i == 0) return nums[i];
        //if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];

        int pick = canRob(i - 2, nums, dp, end) + nums[i];
        int notPick = canRob(i -1, nums, dp, end) + 0; 

        return dp[i] = max(pick, notPick);
    }


    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), -1);

        int incN = canRob(nums.size() - 1, nums, dp, 1);
        vector<int> dp1(nums.size(), -1);
        int nonN = canRob(nums.size() - 2, nums, dp1, 0);

        return max(incN, nonN);
    }
};