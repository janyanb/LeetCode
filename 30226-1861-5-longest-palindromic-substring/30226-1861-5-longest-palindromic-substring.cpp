class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1){
            return s;
        }
        int start = 0, maxlength = 0;

        auto ExpandAroundCenter = [&](int left, int right){
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left --;
                right ++;
            }
            return right - left - 1;
        };

        for(int i = 0; i < s.size(); i++){
            int len1 = ExpandAroundCenter(i,i);  //odd length palindrome
            int len2 = ExpandAroundCenter(i, i+1); //even length palindrome
            int len = max(len1,len2);

            if(len > maxlength){
                maxlength = len;
                start = i - (len -1)/2;
            }
        }

        return s.substr(start, maxlength);
        
    }
};