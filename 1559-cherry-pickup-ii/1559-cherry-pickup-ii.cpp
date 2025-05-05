class Solution {
public:
    int findMaxCherries(int i, int j1, int j2, vector<vector<int>>&grid, int rows, int cols, vector<vector<vector<int>>>& dp){
        if(j1< 0 || j2>= cols || j1 >= cols || j2 < 0) return -1e9;
        if(i == rows -1){
            if(j1 == j2){
                return grid[i][j1];
            } else {
                return (grid[i][j1] + grid[i][j2]);
            }
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxCherries = -1e9;
        for(int c1 = -1; c1 <= 1; c1++){
            for(int c2 = -1; c2 <= 1; c2++){
                maxCherries = max(maxCherries, findMaxCherries(i+1, j1 + c1, j2 + c2, grid, rows, cols, dp));
            }
        }

        if(j1 == j2){
            return dp[i][j1][j2] = (grid[i][j1] + maxCherries);
        } else {
            return dp[i][j1][j2] = (grid[i][j1] + grid[i][j2] + maxCherries);
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return findMaxCherries(0, 0, m-1, grid, n, m, dp);
    }
};