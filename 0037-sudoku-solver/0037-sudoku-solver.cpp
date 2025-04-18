class Solution {
public:
    bool isValid(int row, int col, char num, vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            if(board[row][i] == num) return false;

            if(board[i][col] == num)return false;

            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == num) return false;   //checks box
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char num = '1'; num <= '9'; num++){
                        if(isValid(i, j, num, board)){
                            board[i][j] = num;


                            if(solve(board) == true){
                                return true;
                            } else {
                            board[i][j] = '.';
                            }

                            }                        

                        }

                    return false;
                }
            }

        }

        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};