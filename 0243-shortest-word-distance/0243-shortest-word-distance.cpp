class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int ind1 = -1, ind2 = -2;
        int minDis = INT_MAX;

        for(int i = 0; i< wordsDict.size(); i++){
            if(word1 == wordsDict[i]) ind1 = i;
            if(word2 == wordsDict[i]) ind2 = i;
            if(ind1 >= 0 && ind2 >=0) minDis = min(minDis, abs(ind1 - ind2));
        }

        return minDis;
    }
};