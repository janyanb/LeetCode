class Solution {
public:
    int findWays(string s, int i, vector<int>& dp){
        if(i > s.size() || s[i] == '0') return 0;
        if(i == s.size()) return 1;
        if(dp[i] != -1) return dp[i];        

        int left = findWays(s, i+1, dp);

        int right = 0;
        if(i+1 < s.size()){
            int two = (s[i] -'0')*10 + (s[i+1] -'0');
            if(two >= 10 && two <= 26){
                right = findWays(s, i+2, dp);
            }
        }
        

        return dp[i] = left + right;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
       return findWays(s, 0, dp); 
    }
};