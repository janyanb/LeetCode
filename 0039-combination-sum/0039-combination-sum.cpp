class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> Combinations;
        function<void(int, vector<int>, int)> dfs = [&](int i, vector<int> currComb, int total){
            if(total == target){
                //vector<int> copy = currComb; 
                result.push_back(currComb);
                return;
            };
            //conditiond where dfs ends
            if(i >= candidates.size() || total > target){
                return;
            }


            currComb.push_back(candidates[i]);
            dfs(i, currComb, total + candidates[i]);

            currComb.pop_back();
            dfs(i+1, currComb, total);
        };

        dfs(0, Combinations, 0);

        return result;
    }
};