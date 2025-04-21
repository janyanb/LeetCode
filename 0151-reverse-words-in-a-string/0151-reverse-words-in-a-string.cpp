class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        vector<string> words;
        string word;

        while(i >= 0){
            while(i >= 0 && s[i] == ' '){
                i--;
            }

            while(i >=0 && s[i] != ' '){
                word += s[i];
                i--;
            }
            if(!word.empty()){
                reverse(word.begin(), word.end());
                words.push_back(word);
                word.clear();
            }

        }

        string res;
        int j = 0;
        while(j < words.size() - 1){
            res += words[j] + ' ';
            j++;
        }
        res += words[j];

        return res;
    }
};