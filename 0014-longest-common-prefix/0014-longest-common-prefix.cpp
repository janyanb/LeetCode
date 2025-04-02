class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = ""; 
        if(strs.size() == 1) return strs[0];

        for(int j = 1; j<=strs[0].size(); j++){
            prefix = strs[0].substr(0,j);
            for(int i = 1; i < strs.size(); i++){                
                if(strs[i].substr(0,j) != prefix){
                    return prefix.substr(0, prefix.size() -1);
                }                
            }
        }
        return prefix;
    }
};