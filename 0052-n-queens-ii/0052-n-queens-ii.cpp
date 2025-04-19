class Solution {
public:
    bool isValid(int row, int col, vector<string>& board, int n){
        int temprow = row;
        int tempcol = col;
        while(temprow>= 0 && tempcol>= 0){
            if(board[temprow][tempcol] == 'Q') return false;
            temprow--;
            tempcol--;
        }

        temprow = row;
        tempcol = col;
        while(tempcol>= 0){
            if(board[temprow][tempcol] == 'Q') return false;
            tempcol --;
        }

        tempcol = col;
        temprow = row;
        while(temprow<n && tempcol >= 0){
            if(board[temprow][tempcol] == 'Q') return false;
            temprow ++;
            tempcol--;
        }

        return true;
    }

    int findComb(int col, vector<string>& board, int n){
        if(col == n){
            return 1;
        }

        int total = 0;
        for(int row = 0; row<n; row++){
            if(isValid(row, col, board, n)){
                board[row][col] = 'Q';
                total += findComb(col + 1, board, n);
                board[row][col] = '.';
            }
        }

        return total;
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        return findComb(0, board, n);
    }
};