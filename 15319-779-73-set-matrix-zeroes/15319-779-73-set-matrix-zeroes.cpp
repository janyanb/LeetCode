class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> rows;
        unordered_set<int> cols;

        for(int r=0; r<n; r++){
            for(int c =0; c<m; c++){
                if(matrix[r][c] == 0){
                    rows.insert(r);
                    cols.insert(c);
                }
            }
        };

        for(int r=0; r<n; r++){
            for(int col: cols){                    //iterates over all rows and marks 0 in every col
                matrix[r][col] = 0;
            }
        };

        for(int row: rows){
            matrix[row] = vector<int>(m, 0);
        };
        
    }
};