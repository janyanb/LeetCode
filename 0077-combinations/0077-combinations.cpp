class Solution {
public:
    void findComb(int ind, vector<int>& arr, vector<int>& comb, vector<vector<int>>& res, int k){        
        if(comb.size() == k){
            res.push_back(comb);
            return;
        }

        if(ind >= arr.size()) return;

        comb.push_back(arr[ind]);
        findComb(ind + 1, arr, comb, res, k);

        comb.pop_back();
        findComb(ind + 1, arr, comb, res, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        vector<int> arr;
        for(int i = 1; i<=n; i++){
            arr.push_back(i);
        }
        findComb(0, arr, comb, res, k);

        return res;
    }
};