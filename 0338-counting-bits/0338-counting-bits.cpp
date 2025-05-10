class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            vector<int> setbits;
            int num = i;
            while(num!=0){
                setbits.push_back(num%2);
                num = num/2;
            }
            ans.push_back(count(setbits.begin(), setbits.end(), 1));
        };
        return ans;
    }
};