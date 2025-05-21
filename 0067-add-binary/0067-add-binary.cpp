class Solution {
public:
// int convertToBinary(string num){
//     int pow = 1;
//     for(int i = nums.size() - 1; i >=0; i--){
//         res += (num[i] - '0') * pow;
//         pow *= 2;
//     }

//     return res;
// }
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() -1;
        int carry = 0;
        string res;
        while(i >= 0 ||j >=0 ||carry){
            int dig1 = (i >= 0)? a[i] - '0': 0;
            int dig2 = (j >= 0)? b[j] - '0': 0;

            int sum = carry + dig1 + dig2;
            res += (sum%2) + '0';
            carry = sum/2;


            i--;
            j--;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};