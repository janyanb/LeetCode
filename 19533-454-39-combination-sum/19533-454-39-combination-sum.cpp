class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> Combinations;
        function<void(int, vector<int>, int)> dfs = [&](int i, vector<int> currComb, int total){
            if(total == target){
                vector<int> copy = currComb; 
                result.push_back({copy});
                return;
            };
            //conditiond where dfs ends
            if(i >= candidates.size() || total > target){
                return;
            }

            //1st half of the tree where i is included for the first time
            currComb.push_back(candidates[i]);
            dfs(i, currComb, total + candidates[i]);

            //2nd half where i is not included to prevent same combinations
            currComb.pop_back();
            dfs(i+1, currComb, total);
        };

        dfs(0, Combinations, 0);

        return result;
    }
};