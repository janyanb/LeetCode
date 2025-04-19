class Solution {
public:
    bool isPalindrome(int start, int end, string s){
        while(start <= end){
            if(s[start] !=  s[end]) return false;
            start ++;
            end --;
        }

        return true;
    }
    void findPartition(int ind, vector<string>& currComb, vector<vector<string>>& res, string s){
        if(ind == s.size()) {
            res.push_back(currComb);
            return;
        }

        for(int i = ind; i<s.size(); i++){
            if(isPalindrome(ind, i, s)){
                currComb.push_back(s.substr(ind, i - ind + 1));
                findPartition(i+ 1, currComb, res, s);
                currComb.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> comb;
        findPartition(0, comb, res, s);

        return res;
    }
};