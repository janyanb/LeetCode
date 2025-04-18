class Solution {
public:
    bool isValid(int row, int col, vector<string>& board, int n){
        int temprow = row;
        int tempcol = col;

        while(temprow>=0 && tempcol>=0){
            if(board[temprow][tempcol] == 'Q') return false;
            temprow --;
            tempcol --;
        }
        
        temprow = row;
        tempcol = col;
        while(tempcol >= 0){
            if(board[temprow][tempcol] == 'Q') return false;
            tempcol--;
        }

        temprow = row;
        tempcol = col;
        while(temprow<n && tempcol>=0){
            if(board[temprow][tempcol] == 'Q') return false;
            temprow ++;
            tempcol --;
        }

        return true;
    }
    void findComb(int col, vector<string>& board, vector<vector<string>>& res, int n){
        if(col == n){
            res.push_back(board);
            return;
        }

        for(int row = 0; row<n; row++){
            if(isValid(row, col, board, n)){
                board[row][col] = 'Q';
                findComb(col + 1, board, res, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n,'.'));

        findComb(0, board, res, n);

        return res;
    }
};