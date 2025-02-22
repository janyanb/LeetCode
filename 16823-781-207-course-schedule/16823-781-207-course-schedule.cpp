class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for(auto edge : prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(numCourses, false);
        function<bool(int)> dfs = [&](int curr){
            if(visited[curr]) return false;
            if(graph[curr].empty()) return true;

            visited[curr] = true;
            for(int nei: graph[curr]){
                if(!dfs(nei)){
                    return false;
                }             
            }
            visited[curr] = false;    // the visited vector will be reused by another graph so once this graph is explored mark as false.
            graph[curr].clear();   //form of memoization
            return true;
        };

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)){
                return false;     //to make sure all graphs are checked(there may be multiple courses which have prerequisites)
            }
        };
        return true;
    }
};