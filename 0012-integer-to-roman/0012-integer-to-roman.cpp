class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>>intToSymbol{
           {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}
        };

        string result;

        for(auto [number,symbol] : intToSymbol){
            if(num == 0) break;
            while(num >= number){
                num -= number;
                result += symbol;
            } 
        }
        return result;   
    }
};