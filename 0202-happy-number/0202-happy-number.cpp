class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        while(n>1){
            vector<int> digits;
            while(n>=10){
                int digit = n%10;
                digits.push_back(digit);
                n=n/10;
            }
            digits.push_back(n);

            int Totaldig = 0;
            for(int i = 0; i< digits.size(); i++){
                int num = digits[i];
                Totaldig += num * num;                
            }
            if(nums.find(Totaldig) != nums.end()) return false;
            nums.insert(Totaldig);

            n = Totaldig;
        }
        return true;
    }
};