class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int left = 0, right = 0;
        while(right< t.size()){
            if(s[left] == t[right]){
                if(left == s.size() -1) return true;
                left++;
                //right++;
            } 
            right++;
        }
        return false;
    }
};