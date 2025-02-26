class Solution {
public:
    bool isPalindrome(string s) {
        string str;

        for( auto letter: s){
            if(isalnum(letter)){
                str += letter;
            };
        };

        transform(str.begin(), str.end(), str.begin(), ::tolower);
        string orstring =  str;

        reverse(str.begin(), str.end());

        if(str == orstring) return true;

        return false;
    }
};