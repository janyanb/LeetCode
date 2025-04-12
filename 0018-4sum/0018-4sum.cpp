class Solution {
// private: vector<vector<int>> result;
public:
    // void findQuadruplets(int ind, vector<int>& ds, int sum, vector<int>& nums, int target, int nSize){
    //     if(ind >= nSize){
    //         if(sum == target && ds.size() == 4){
    //             vector<int> copy(ds.begin(), ds.end());
    //             sort(copy.begin(), copy.end());
    //             auto found = find(result.begin(), result.end(), copy);
    //             if(found== result.end()) {
    //                 result.push_back(copy);
    //             }
    //         }
    //         return;
    //     }

    //     //pick
    //     ds.push_back(nums[ind]);
    //     sum += nums[ind];
    //     findQuadruplets(ind + 1, ds, sum, nums, target, nSize);

    //     //not pick
    //     ds.pop_back();
    //     sum -= nums[ind];
    //     findQuadruplets(ind + 1, ds, sum, nums, target, nSize);
    // }

    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     vector<int> ds;

    //     findQuadruplets(0, ds, 0, nums, target, nums.size());

    //     return result;
    // }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        if(nums.size() < 4) return result;

        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size() - 3; i++){
            if(i > 0 && nums[i] == nums[i -1]) continue;
            for(int j = i+1; j<nums.size() -2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while(left < right){
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target){
                        left ++;
                    } else if(sum > target){
                        right --;
                    } else if(sum == target){
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left ++;
                        while(nums[left] == nums[left -1] && left < right){
                            left++;
                        }                        
                    }
                }
            }
        }

        return result;
    }
};

