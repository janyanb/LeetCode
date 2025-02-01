class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        if(n <=1 ){
            return n;
        }

        auto ExpandAroundCenter = [&](int left, int right){
            int count = 0;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left --;
                right ++;
                count ++;
            }
            return count;
        };

        int total = 0;
        for(int i = 0; i < n; i++){

           int count1 = ExpandAroundCenter(i,i); //odd length
           int count2 = ExpandAroundCenter(i,i+1); //even length

           int count = count1 + count2;
           total += count;      

        };

        return total;
        
    }
};