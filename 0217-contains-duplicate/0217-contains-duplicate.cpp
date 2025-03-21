class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        if (nums.size() != numSet.size()) return true;

        return false;
    }
};