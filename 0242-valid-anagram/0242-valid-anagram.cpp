class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> wordCount;

        for(int i = 0; i< s.size(); i++){
            wordCount[s[i]]++;
        }

        for (int j = 0; j< t.size(); j++){
            if(wordCount[t[j]] > 0){
                wordCount[t[j]]--;
            } else {
                return false;
            }
        }

        return true;
    }
};