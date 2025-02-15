class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(); int cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols)); 
        vector<vector<bool>> atl(rows, vector<bool>(cols));  

        function<void(int,int,vector<vector<bool>>&,int)>   dfs = [&](int cr, int cc, vector<vector<bool>>& visited, int prevheight){
            if (cr < 0 || cr >= rows || cc < 0 || cc >= cols || heights[cr][cc] < prevheight || visited[cr][cc]){
                return;
            } else {
                visited[cr][cc] = true;
                dfs(cr+1, cc, visited, heights[cr][cc]);
                dfs(cr-1, cc, visited, heights[cr][cc]);
                dfs(cr, cc+1, visited, heights[cr][cc]);                
                dfs(cr, cc-1, visited, heights[cr][cc]);
            }

        };
        for(int c = 0; c<cols;c++){
            dfs(0, c, pac, heights[0][c]);
            dfs(rows - 1, c, atl, heights[rows - 1][c]);
        };

        for(int r = 0; r<rows;r++){
            dfs(r, 0, pac, heights[r][0]);
            dfs(r, cols - 1, atl, heights[r][cols - 1]);
        };

        vector<vector<int>> result;
        for(int r = 0; r < rows;r++){
            for(int c = 0; c < cols; c++){
                if (pac[r][c] && atl[r][c]){
                    result.push_back({r,c});
                }
            }
        }

    return result;   
    }
};