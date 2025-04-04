class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int left = 0, right = matrix[0].size() -1;
        int top = 0, bottom = matrix.size() -1;
        vector<int> result;

        while(left<=right && top<=bottom){
            for(int i = left; i<=right; i++){
                result.push_back(matrix[top][i]);
            }top++;

            if(top>bottom)break;

            for(int j = top; j<=bottom; j++){
                result.push_back(matrix[j][right]);
            }right--;

            if(right<left)break;


            for(int k = right; k>=left; k--){
                result.push_back(matrix[bottom][k]);
            }bottom--;

            for(int m = bottom; m>=top; m--){
                result.push_back(matrix[m][left]);
            }left++;
        }

    return result;  
    }
};