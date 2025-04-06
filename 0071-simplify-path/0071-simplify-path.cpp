class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string dir;
        int i = 0;
        
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') {
                i++;
            }
            // Extract the next directory name.
            while (i < path.size() && path[i] != '/') {
                dir.push_back(path[i]);
                i++;
            }
            if (!dir.empty()) {
                if (dir == ".") {
                } else if (dir == "..") {
                    if (!s.empty()) s.pop();
                } else {
                    s.push(dir);
                }
                dir.clear();  
            }
        }
        
        string result;
        while (!s.empty()) {
            result = "/" + s.top() + result;
            s.pop();
        }
        return result.empty() ? "/" : result;
    }
};
