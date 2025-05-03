class Solution {
public:
    int findPath(int m, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(m == triangle.size() - 1){
            return triangle[m][n];
        }

        if(m > triangle.size() -1) return INT_MAX;

        if(dp[m][n] != -1) return dp[m][n];

        int down = findPath(m + 1, n, triangle, dp);
        int diag = findPath(m + 1, n + 1, triangle, dp);

        return dp[m][n] = triangle[m][n] + min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findPath(0, 0, triangle, dp);
    }
};