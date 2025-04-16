class Solution {
private: vector<vector<int>> res;
public:
    void findCombinations(int ind, int sum, vector<int>& combination, vector<int>& candidates, int target){
        //if(ind > candidates.size() || sum > target) return;
        if(sum == target){ 
            res.push_back(combination);
            return;
        }

        for(int i = ind; i<candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target || target< sum + candidates[i]) break;
            combination.push_back(candidates[i]);
            findCombinations(i+1, sum + candidates[i], combination, candidates, target);
            combination.pop_back();
        }

    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        findCombinations(0, 0, combination, candidates, target);

        return res;
    }
};