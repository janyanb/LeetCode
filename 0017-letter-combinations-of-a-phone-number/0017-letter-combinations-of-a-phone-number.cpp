class Solution {
private: vector<string> res; 

public:
    void calcCombination(string& digits, vector<string>&Map, string& temp, int index){
        if(index == digits.size()){
            res.push_back(temp);
            return;
        }

        string curr = Map[digits[index] - '0'];
        for(int i = 0; i<curr.size(); i++){
            temp.push_back(curr[i]);
            calcCombination(digits, Map, temp, index+1);
            temp.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;

        vector<string> numMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;
    
        calcCombination(digits, numMap, temp, 0);

        return res;
    }
};