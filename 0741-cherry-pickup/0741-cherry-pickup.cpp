class Solution {
public:
    int findPath(int r1, int c1, int r2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int c2 = (r1 + c1) - r2;

        if(r1 >= grid.size() || r2 >= grid.size() || c1 >= grid.size() || c2>= grid.size() || grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;

        if(r1 == grid.size() -1 && c1 == grid.size() - 1){
            return grid[r1][c1];                                                  //total number of steps to get to n-1 will be same for person1 and person2
        }
        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int down1 = findPath(r1 + 1, c1, r2, grid, dp);
        int down2 = findPath(r1 + 1, c1, r2 + 1, grid, dp);
        int right1 = findPath(r1, c1 + 1, r2, grid, dp);
        int right2 = findPath(r1, c1 + 1, r2 + 1, grid, dp);

        int maxCh = max(down1, max(down2, max(right1, right2)));

        if(r1 == r2 || c1 == c2){                                          //if (r1 == r2 then c1 == c2 because r1 + c1 = r2 + c2)
            return dp[r1][c1][r2] = grid[r1][c1] + maxCh;
        } else {
            return dp[r1][c1][r2] = grid[r1][c1] + grid[r2][c2] + maxCh;
        }
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int cherries = findPath(0,0,0, grid, dp);

        return max(0, cherries);
    }
};