class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while(i< word.size() && j<abbr.size()){
            if(isalpha(abbr[j])){
                if(abbr[j] != word[i]) return false;
                i++;
                j++;
            } else {
                if(abbr[j] == '0') return false;

                int num = 0;
                while(j < abbr.size() && isdigit(abbr[j])){
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }

                i+=num;
            }
        }

        return i == word.size() && j == abbr.size();        

    }
};