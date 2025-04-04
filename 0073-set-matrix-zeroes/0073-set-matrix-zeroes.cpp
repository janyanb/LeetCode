class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int matrixRows = matrix.size();
        int matrixCols = matrix[0].size();

        unordered_set<int>rows;
        unordered_set<int>cols;

        for(int i = 0; i<matrixRows; i++){
            for(int j = 0; j<matrixCols; j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(int i = 0; i<matrixRows; i++){
            for(int j = 0; j< matrixCols; j++){
                if(rows.find(i)!=rows.end()){
                    matrix[i] = vector<int>(matrixCols, 0);
                    break;
                }
                if(cols.find(j) != cols.end()) matrix[i][j] = 0;
            }
        }
    }
};