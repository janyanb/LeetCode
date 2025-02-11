class Solution {
public:
    string alienOrder(vector<string>& words) {
        // Graph: letter -> set of letters that come after it.
        unordered_map<char, unordered_set<char>> graph;
        // Indegree: letter -> number of incoming edges.
        unordered_map<char, int> indegree;
        
        // Initialize the graph and indegree for every unique letter.
        for (const string &word : words) {
            for (char c : word) {
                if (!graph.count(c)) {
                    graph[c] = unordered_set<char>();
                }
                if (!indegree.count(c)) {
                    indegree[c] = 0;
                }
            }
        }
        
        // Build the graph by comparing adjacent words.
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i], word2 = words[i+1];
            // Check for an invalid case: e.g., "abc" and "ab"
            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
                return "";
            }
            int len = min(word1.size(), word2.size());
            for (int j = 0; j < len; j++) {
                char c1 = word1[j], c2 = word2[j];
                if (c1 != c2) {
                    // If there's not already an edge from c1 to c2, add it.
                    if (!graph[c1].count(c2)) {
                        graph[c1].insert(c2);
                        indegree[c2]++;
                    }
                    break;  // Only the first different character matters.
                }
            }
        }
        
        // Use BFS (Kahn's algorithm) for topological sorting.
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }
        
        string result;
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result.push_back(curr);
            for (char neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If the result length does not equal the number of unique letters,
        // it means there's a cycle, so the order is invalid.
        if (result.size() != indegree.size()) {
            return "";
        }
        
        return result;
    }
};
