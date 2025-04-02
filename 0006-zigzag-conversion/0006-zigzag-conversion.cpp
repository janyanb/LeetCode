class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows) return s;
        int i = 0, currRow = 0, jumps = 0;
        string result;
        result += s[0];
        while(currRow < numRows){
            if(currRow != 0 && currRow != numRows - 1){
                while(i < s.size()){
                    jumps = (numRows - 1) * 2 - (2 * currRow);
                    if( i + jumps <s.size()) result += s[i+ jumps];
                    i += (numRows -1) * 2;
                    if( i <s.size()) result += s[i];                    
                }
                currRow++;
                i = currRow;
                result += s[i];
            } else {
                while(i < s.size()){
                    jumps = (numRows - 1) * 2;
                    i += jumps;
                    if( i <s.size()) result+= s[i];
                }
                currRow++;
                i = currRow;
                if(currRow != numRows) result += s[i];                
            }
        }
        return result;
    }
};