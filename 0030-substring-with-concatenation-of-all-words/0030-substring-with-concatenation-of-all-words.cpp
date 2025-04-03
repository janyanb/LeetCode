class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //use hashtable to count occurances of word
        //sliding window to keep track of substring

        unordered_map<string,int> wordCount;
        int wordLen = words[0].size();
        int numWords = words.size();
        int windowSize = wordLen * numWords;
        vector<int> res;

        for(auto word: words){
            wordCount[word]++;
        }

        for(int i = 0; i<wordLen; i++){
            int left = i, right = i;
            unordered_map<string,int> windowWords;

            while(right + wordLen <= s.size()){
                string word = s.substr(right,wordLen);
                right +=wordLen;

                if(wordCount.count(word)){
                    windowWords[word]++;

                    while(windowWords[word] > wordCount[word]){
                        string leftword = s.substr(left, wordLen);
                        windowWords[leftword]--;
                        left +=wordLen;
                    }

                    if(right - left == windowSize){
                        res.push_back(left);
                    }
                } else{ 

                    windowWords.clear();
                    left = right;
                }

            }

        }
        return res;
    }
};