class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mapCS;
        unordered_map<string, char> mapSC;

        vector<string> str;
        string word;
        for(char alpha: s){
            if(isalpha(alpha)){
                word+=alpha;
            }else{
                str.push_back(word);
                word.clear();
            } 
        }
        str.push_back(word);

        if(pattern.size() != str.size()) return false;

        for(int i = 0; i<pattern.size(); i++){

            if(mapCS.count(pattern[i])){
                if(mapCS[pattern[i]] != str[i]) return false;
            } else {
                mapCS[pattern[i]] = str[i];
            }

            if(mapSC.count(str[i])){
                if(mapSC[str[i]] != pattern[i]) return false;
            } else {
                mapSC[str[i]] = pattern[i];
            }
        }

        return true;
    }
};