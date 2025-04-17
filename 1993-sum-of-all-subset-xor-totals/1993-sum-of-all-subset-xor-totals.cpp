class Solution {
public:
    void findSubsets(int ind, vector<int>& comb,vector<vector<int>>& subset, vector<int>& nums){
        if(ind >= nums.size()){
            subset.push_back(comb);
            return;
        }

        comb.push_back(nums[ind]);
        findSubsets(ind + 1, comb, subset, nums);

        comb.pop_back();
        findSubsets(ind + 1, comb, subset, nums);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> comb;
        findSubsets(0,comb,subsets,nums);

        int c = 0, sum = 0;
        for(int i = 0; i<subsets.size(); i++){
            for(int j = 0; j<subsets[i].size(); j++){
                c ^= subsets[i][j]; 
            }
            sum += c;
            c = 0;
        }

        return sum;
    }
};