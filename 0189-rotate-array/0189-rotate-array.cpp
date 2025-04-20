class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();       

        k = k % size;
        int numShift = size - k;

        vector<int> dummy(nums.begin(), nums.end());
        nums.clear();
        nums.insert(nums.begin(), dummy.begin() + numShift, dummy.end());
        nums.insert(nums.begin() + k, dummy.begin(), dummy.begin() + numShift);
    }
};