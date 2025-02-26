class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> MatchingWords;
        vector<string> vec; 

        for(string word: strs){
            string copy = word;
            sort(copy.begin(), copy.end());
            MatchingWords[copy].push_back(word);          
        };

        for(auto pair: MatchingWords){
            result.push_back(pair.second);              //push the vector directly(pair.second), do not need for loop
        };

        return result;
    }
};