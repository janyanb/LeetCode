class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<char> S;
        int open = 0, close = 0;
        string str, res;

        for(char c: s){
            if(c == '(') open++;
            if(c == ')') close++;

            if(open >= close){
                str += c;
            } else {
                close --;
            }
        }

        open = 0, close = 0;
        for(int i = str.size() -1; i >= 0; i--){
            if(str[i] == '(') open++;
            if(str[i] == ')') close++;

            if(close >= open){
                res += str[i];
            } else {
                open --;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};