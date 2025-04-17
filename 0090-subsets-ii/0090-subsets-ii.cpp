class Solution {
public:
    void findSubsets(int ind, vector<int>& ds, vector<vector<int>>& res, vector<int>& nums){
        //if(ind >= nums.size()) return;
        res.push_back(ds);

        for(int i = ind; i<nums.size(); i++){
            if(i>ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i+1, ds, res, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, ds, res, nums);

        return res;
    }
};