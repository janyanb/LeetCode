class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() -1;
        while(s[i] == ' '){
            s.pop_back();
            i--;
        }

        stringstream ss(s);
        vector<string> res;
        string str;
        while(getline(ss, str, ' ')){
            res.push_back(str);
        }

        string last = res.back();
        cout<<last;

        return last.size();     
    }
};