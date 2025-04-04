class Solution {
public:
    int countliveCells(int r, int c, int rows, int cols, vector<vector<int>>& board){
        int livecell = 0;
        for(int i = -1; i<= 1; i++){
            for(int j = -1; j <=1; j++){
                if(i == 0 && j == 0) continue;
                int row = r+i;
                int col = c+j;                
                if(row>=0 && col>=0 && row<rows && col<cols){
                    if(board[row][col] == 1){
                        livecell++;
                    }
                }
            }
        }
        return livecell;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size(); //rows
        int c = board[0].size(); //cols

        vector<vector<int>> newState(r,vector<int>(c));
            for(int i =0; i<r;i++){
                for(int j = 0; j<c;j++){
                    int nei = countliveCells(i,j,r,c, board);
                    if(board[i][j]){
                        //underpopulation
                        if(nei< 2) newState[i][j] = 0;
                        //lives in the next gen
                        if(nei == 2 || nei == 3) newState[i][j] = 1;
                        //overpopulation
                        if(nei>3) newState[i][j] = 0;
                    } else {
                        if(nei == 3) newState[i][j] = 1;
                    }
                }
            }

            for(int i = 0; i< r; i++){
                for(int j = 0; j<c; j++){
                    board[i][j] = newState[i][j];
                }
            }
    }
};