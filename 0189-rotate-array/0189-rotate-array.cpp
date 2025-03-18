class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();       

        k = k % size;
        int numShift = size - k;

        vector<int> dummy(nums.begin() + numShift, nums.end());
        dummy.insert(dummy.end(), nums.begin(), nums.end() - k);
        nums = dummy;
     
    }
};