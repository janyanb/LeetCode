class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        
        for (char c : s) {
            
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                
                if (st.empty()) {
                    return false;
                }
                
                // Check the top of the stack for a matching opening bracket.
                char top = st.top();
                st.pop();
                
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        

        return st.empty();
        
    }
};