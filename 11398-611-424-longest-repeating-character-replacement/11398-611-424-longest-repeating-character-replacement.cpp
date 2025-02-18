class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0; 
        unordered_map<char,int> Count;
        int res = 0;

        auto max_element = [&](unordered_map<char,int> Hash){
            int max = 0;
            for(auto entry : Hash){
                if(entry.second > max){
                    max = entry.second;
                }
            }
            return max;
        };


        while(right < s.size()){
            if(Count.find(s[right]) == Count.end()){
                Count[s[right]] = 1;
            } else {
                Count[s[right]] += 1;
            };

            while((right - left + 1) - max_element(Count) > k){
                Count[s[left]] -= 1;
                left ++;
            };

            res = max(right-left+1, res);
            right ++;
        };

        return res;
        
    }
};