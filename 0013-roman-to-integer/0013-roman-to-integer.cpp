class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> SymbolMap;
        SymbolMap['I'] = 1;
        SymbolMap['V'] = 5;
        SymbolMap['X'] = 10;
        SymbolMap['L'] = 50;
        SymbolMap['C'] = 100;
        SymbolMap['D'] = 500;
        SymbolMap['M'] = 1000;

        int i = 0, tot = 0;
        while(i< s.size()){
            if(i+1 <s.size() && SymbolMap[s[i]] < SymbolMap[s[i+1]]){
                tot += SymbolMap[s[i+1]] - SymbolMap[s[i]];
                i+=2;
            } else {
                tot += SymbolMap[s[i]];
                i++;
            }
        }
        return tot;
    }
};