class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> res;
        unordered_map<char, int> maxFreq;

        for(int i = 0; i< words2.size(); i++){
            unordered_map<char, int> Word2;
            for(char c: words2[i]){
                Word2[c]++;
            }


            for(auto [ch, ct]: Word2){
                int maxCt = max(ct, maxFreq[ch]);
                maxFreq[ch] = maxCt;
            }
        }

        for(int j = 0; j<words1.size(); j++){
            unordered_map<char, int> Word1;
            for(char c: words1[j]){
                Word1[c]++;
            }

            bool flag = true;
            for(auto pair: maxFreq){
                if(Word1[pair.first] < pair.second){
                    flag = false;
                    break;
                }
            }

            if(flag) res.push_back(words1[j]);
        }

        return res;
    }
};