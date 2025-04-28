class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int i = n - 2;
        int num = digits[n-1] + 1;
        digits[n -1] = num%10;
        int carry = num/10;


        while(carry && i>= 0){
            num = digits[i] + carry;
            digits[i] = num%10;
            carry = num/10;
            i--;            
        }

        if(carry) digits.insert(digits.begin(), 1);

        return digits;
    }
};