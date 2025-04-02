class Solution {
public:
    string evenlines(vector<string> words, int len, int maxWidth){
        int whitespaces = maxWidth - len;
        int gaps = words.size() -1;

        int padding = (gaps > 0)? whitespaces/gaps: 0;
        int unevenPad = (gaps> 0)? whitespaces % gaps : 0;
        string line;

        for(int i =0; i<words.size(); i++){
            line += words[i];
            if(gaps == 0) line += string(whitespaces, ' ');

            if(i< gaps){
                line += string(padding, ' ');
                if(unevenPad > 0){
                    line+= ' ';
                    unevenPad--;
                }
            } 
        }
         
        return line;
    };

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> linewords;
        int len = 0;
        for(int i = 0; i<words.size(); i++){
            string word = words[i];

            if(len + word.length()+ linewords.size() > maxWidth){
                res.push_back(evenlines(linewords, len, maxWidth));

                linewords.clear();
                len = 0;
            }

            linewords.push_back(word);
            len += word.length();

        }

        //left-justified
        string line;
        for(int i =0; i<linewords.size(); i++){
            line += linewords[i];
            if(i < linewords.size() - 1){
                line += ' ';
            }
        }
        int rightpad = max(0, maxWidth - static_cast<int>(line.size()));
        line+=string(rightpad, ' ');
        res.push_back(line);

        return res;
    }
};