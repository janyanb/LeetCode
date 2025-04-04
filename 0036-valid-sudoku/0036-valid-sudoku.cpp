class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        unordered_set<char> cellValue;
        //check for validity in row
        for(int i = 0; i< rows; i++){
            for(int j = 0; j< cols; j++){
                if(board[i][j] == '.') continue;
                if(cellValue.find(board[i][j]) != cellValue.end()) return false;
                cellValue.insert(board[i][j]);
            }
            cellValue.clear();
        }

        //check validity for cols
        for(int j = 0; j< cols; j++){
            for(int i = 0; i< rows; i++){
                if(board[i][j] == '.') continue;
                if(cellValue.find(board[i][j]) != cellValue.end()) return false;
                cellValue.insert(board[i][j]);
            }
            cellValue.clear();
        }

        // Check all 3×3 sub-boxes in a 9×9 board
        for (int boxStartRow = 0; boxStartRow < 9; boxStartRow += 3) {
            for (int boxStartCol = 0; boxStartCol < 9; boxStartCol += 3) {
                
                unordered_set<char> cellValue;
                
                // Each sub-box covers 3 rows and 3 columns
                for (int r = boxStartRow; r < boxStartRow + 3; r++) {
                    for (int c = boxStartCol; c < boxStartCol + 3; c++) {
                        char val = board[r][c];
                        if (val == '.') continue;  
                        
                        if (cellValue.find(val) != cellValue.end()) {
                            return false; 
                        }
                        cellValue.insert(val);
                    }
                }
            }
        }

    return true;    
    }
};