class Solution {
public:
    int lengthOfLastWord(string s) {
        regex pattern("([a-zA-Z]+)\\s*$");
        smatch matches;

        regex_search(s, matches, pattern);
        string word = matches[1];
        return word.size();
        
    }
};