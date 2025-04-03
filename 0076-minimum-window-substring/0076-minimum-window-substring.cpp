class Solution {
public: 
    string minWindow(string s, string t) {
        if(t.size() == s.size() && t == s) return t;
        //if we have to compare chars from one string in another. If cahr exists in map count++, Decrement char value in main string. 
        unordered_map<char, int> charFreq;

        for(char letter: t){
            charFreq[letter]++;
        }

        int left = 0, right = 0;
        int count = 0, minlen = INT_MAX, start = -1;
        while(right<s.size()){
            if(charFreq[s[right]] > 0) count++;
            charFreq[s[right]]--;

            while(count == t.size()){
                int window = right - left + 1;
                if(window < minlen){
                    minlen = window;
                    start = left;
                }

                charFreq[s[left]]++;
                if(charFreq[s[left]] > 0) count--;
                left++;
            }

            right++;
        }

        return (start!=-1)? s.substr(start, minlen) : "";
    }
};





// public:
//     string minWindow(string s, string t) {
//         //sliding window apprach, start from 0 and increment by 1 and check if letter from t exists.
//         //use hashtable to keep count of characters
//         if(t.size() > s.size()) return "";
//         if(t.size() == s.size() && t == s) return t;

//         unordered_map<char, int> charFreq;
//         int minlen = s.size();

//         for(char letter: t){
//             charFreq[letter]++;
//         }
//         int left = 0, right = 0;
//         unordered_map<char, int> windowCount;
//         string substring;
//         while(right<s.size()){
//             char alpha = s[right];
//             windowCount[s[right]]++;
//             right++; 

//             if(charFreq.find(alpha) != charFreq.end()){
//                 while(windowCount[alpha] > charFreq[alpha]){
//                     windowCount[s[left]]--;
//                     left++;
//                 }
//             }

//             while(substringFound(windowCount, charFreq)){
//                 if(windowCount[s[left]] == charFreq[s[left]]) break;
//                 windowCount[s[left]]--;
//                 left++;
//             }

//             if(substringFound(windowCount, charFreq)){
//                 int windowlen = right - left;
//                 if(windowlen < minlen){
//                     minlen = windowlen;
//                     substring = s.substr(left,windowlen);
//                 } 
//             }

//         }

//         return substring;
//     }

//     bool substringFound(unordered_map<char,int>& windowFreq, unordered_map<char,int> charFreq){
//         for(auto [letter,freq]: charFreq){
//             if(windowFreq[letter] < freq) return false;
//         }
//         return true;
//     }
// };