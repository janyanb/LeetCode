class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n) return false;
        unordered_map<char,int> word1;
        unordered_map<char,int> word2;        

        for(char letter : s){
            if(word1.find(letter) != word1.end()) {
                word1[letter] ++;
            } else {
                word1[letter] = 1;
            }
        }

        for(char letter: t){
            if(word2.find(letter) != word2.end()){
                word2[letter] ++;
            } else {
                word2[letter] = 1;
            }
        }

        if(word1 == word2){
            return true;
        };

        return false;
    }
};