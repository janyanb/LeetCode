class Solution {
public:
    int findPath(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n){
        if(row > (n - 1) || col > (n - 1) || col < 0) return 1e9;

        if(row == (n - 1)){
            return matrix[row][col];
        }
        
        if(dp[row][col] != -1) return dp[row][col];

        int dl = findPath(row + 1, col - 1, matrix, dp, n);
        int d = findPath(row + 1, col, matrix, dp, n);
        int dr = findPath(row + 1, col + 1, matrix, dp, n);

        return dp[row][col] = matrix[row][col] + min(dl, min(d,dr));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        //run a for loop from all staring indices(first row)
        //keep a min for every index at start
        // int n = matrix.size();
        // int minPath = INT_MAX;
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int i = 0;i< n; i++){
        //     minPath = min(minPath, findPath(0, i, matrix, dp, n));
        // }

        // return minPath;

        
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int j = 0; j < n ; j++){                    //Write base cases
            dp[n-1][j] = matrix[n-1][j];
        }

        for(int i = n -2; i>= 0; i--){                //outter for loops basically mimic each cell, in recurssion every cell is visited at least once
            for(int j = n -1; j >= 0; j--){           // for row i(number of columns that exist = n-1 -> 0 or vice versa)

                int dl = (j > 0)? dp[i+1][j-1]: 1e9;                    //for each cell traverse the next 3 directions, check for out of bounds
                int d = dp[i+1][j];
                int dr = (j < n-1)? dp[i+1][j+1]: 1e9;          //out of bounds base case

                dp[i][j] = matrix[i][j] + min(dl, min(d, dr));             //getmin of all the cells and store in dp
            }
        }

        int minPath = 1e9;
        for(int c = 0; c< n; c++){
            minPath = min(minPath, dp[0][c]);
        }

        return minPath;
    }
};