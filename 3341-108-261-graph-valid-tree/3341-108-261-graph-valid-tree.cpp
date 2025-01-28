class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }    

        //adjacency list to store graph
        vector<vector<int>> graph(n);
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        } 

        vector<bool> visited(n, false);
        function<bool(int,int)> dfs = [&](int current, int prev){
            if(visited[current]){
                return false;
            }

            visited[current] = true;
            for(int nei: graph[current]){
                if(nei == prev){
                    continue;
                }
                if(!dfs(nei, current)){
                    return false;
                }
            }
            return true;
        };

        if( !dfs(0, -1)){
            return false;
        }

        for(bool isVisited : visited){
            if(!isVisited){
                return false;
            }
        }
        return true;         
    }
};