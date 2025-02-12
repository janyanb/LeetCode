class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for(string current: strs){
            int len = current.size();
            result += to_string(len) + "#" + current;
        };
        //cout<<result;
        return result;        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        //string word;
        int i = 0;
        vector<string> ReturnVector;
        while( i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j += 1;    //compute the starting and ending index of len value
            };
            int length = stoi(s.substr(i,j-i));
            cout<<length;
            i = j+1;
            j = i+length;
            ReturnVector.push_back(s.substr(i, length));
            i = j;            
            };
        return ReturnVector;
        }
};


// Your Codec object will be instantiated and called as such:
/*int main(){
Codec codec;
vector<string> strs = ["hello", "world"];
codec.decode(codec.encode(strs));
return 0;
}*/