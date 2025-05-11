class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if(!n) return 0;

        int count = 0;
        vector<vector<int>> graph(n, vector<int>());
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        function<void(int)> dfs = [&](int curr){
            if(visited[curr]) return;

            visited[curr] = true;
            for(int nei: graph[curr]){
                if(!visited[nei]) dfs(nei);                
            }

        };

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count ++;
                dfs(i);
            }
            

        };

        return count;
    }
};