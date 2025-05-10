class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            vector<int> setbits;
            int num = i;
            while(num!=0){
                if(num%2!=0) setbits.push_back(1);
                num = num/2;
            }
            ans.push_back(setbits.size());
        };
        return ans;
    }
};