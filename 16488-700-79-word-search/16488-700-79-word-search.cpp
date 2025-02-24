class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j< board[0].size(); j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        };
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int pointer){
        int m = board.size();
        int n = board[0].size();

        if(pointer == word.size()){
            return true;
        };

        if( i < 0 || i >= m || j < 0 || j >= n || word[pointer] != board[i][j]){
            return false;
        };

        char temp = board[i][j];
        board[i][j] = '#';            //mark as visited

        bool detected = (dfs(board, word, i+1, j, pointer +1) || dfs(board, word, i-1, j, pointer +1) || dfs(board, word, i, j+1, pointer +1) || dfs(board, word, i, j-1, pointer + 1));

        board[i][j] = temp;

        return detected;
    }
};