class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0, right = 0;
        int maxlength = 0;

        while(right< s.size()){
            if(charSet.find(s[right]) == charSet.end()){
                //adds the char to charSet and increments
                charSet.insert(s[right]);
                maxlength = max(maxlength, right - left + 1);
                right ++;
            } else {
                charSet.erase(s[left]);
                left ++;
            }
        }
        return maxlength;
        
        
    }
};