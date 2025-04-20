class Solution {
public:
    bool isValid(int op, int cl, char c, int n){
        if(c == '('){
            op++;
        } else {
            cl++;
        }

        if(op < cl) return false;
        if(op > n) return false; 

        return true;
    }
    void findParanthesis(string comb, vector<string>& res, int open, int close, int n, string pair){
        if(open == n && close == n){
            res.push_back(comb);
            return;
        }

        for(int i = 0; i<2 ; i++){
            if(isValid(open, close, pair[i], n)){
                comb.push_back(pair[i]);
                if(pair[i] == '('){
                    findParanthesis(comb, res, open + 1, close, n, pair);
                } else {
                    findParanthesis(comb, res, open, close + 1, n, pair);
                }
                comb.pop_back();                
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string comb;
        string pair = "()";

        findParanthesis(comb, res, 0, 0, n, pair);

        return res;
    }
};