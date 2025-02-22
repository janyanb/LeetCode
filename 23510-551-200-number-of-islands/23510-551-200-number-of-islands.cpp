class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >=m || j>=n || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';     //marks all 1s to 0s so call from next outter loop will not increment count.

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j =0;j<n; j++){

            if(grid[i][j] == '1'){
                count ++;
                dfs(grid, i, j);
            }
        }
        }
        return count;
    }
};