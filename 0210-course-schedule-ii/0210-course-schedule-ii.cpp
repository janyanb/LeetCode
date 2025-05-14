class Solution {
public:
    bool dfs(int curr, vector<bool>& visited,vector<bool>& onPath, vector<int>& order, bool &hasCycles, vector<vector<int>>& graph){
        if(onPath[curr]) return hasCycles = true, false;
        if(visited[curr]){
            return true;
        } 

        onPath[curr] = true;
        for(int nei: graph[curr]){
            if(!dfs(nei, visited,onPath, order, hasCycles, graph)) return false;
        }

        onPath[curr] = false;
        visited[curr] = true;
        order.push_back(curr);   //push children first and
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool hasCycles = false;
        vector<vector<int>> graph(numCourses);
        for(auto edge: prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        vector<int> order;

        for(int i = 0; i<numCourses; i++){
            dfs(i, visited,onPath, order, hasCycles, graph);
        }

        return (hasCycles)? vector<int>(): order;
    }
};