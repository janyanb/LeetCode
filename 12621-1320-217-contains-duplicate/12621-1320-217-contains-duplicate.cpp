class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> Count;

        for(int num: nums){
            if(Count.find(num) != Count.end()){
                return true;
            } else {
                Count.insert({num, 1});
            }
        };
        return false;
    }
};