class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        while(i< haystack.size()){
            if(haystack.substr(i, needle.size()) == needle){
                return i;
            }
            i++;
        }
        return -1;
    }
};