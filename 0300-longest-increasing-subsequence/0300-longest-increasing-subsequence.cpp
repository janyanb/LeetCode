class Solution {
public:
    int findSeq(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;

        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int pick = 0;
        if(prev == -1 || nums[ind] > nums[prev]){
            pick = 1 + findSeq(ind + 1, ind, nums, dp);
        }

        int notPick = findSeq(ind + 1, prev, nums, dp);

        return dp[ind][prev + 1] = max(pick, notPick);

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findSeq(0, -1, nums, dp);
    }
};