class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        //if(k == 1) return nums.back();
        return nums[nums.size() - k];
    }
};