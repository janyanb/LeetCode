class Solution {
public:
    void findPerm(vector<int>& ds, vector<vector<int>>& res, vector<int>& nums){
        if(ds.size() == nums.size()){
            res.push_back(ds);
            return;
        }

        for(int i = 0; i< nums.size(); i++){
            auto it = find(ds.begin(), ds.end(), nums[i]);
            if(it != ds.end()) continue;
            ds.push_back(nums[i]);
            findPerm(ds, res, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        findPerm(ds, res, nums);

        return res;
    }
};