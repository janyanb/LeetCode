class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> numCount;

        int majorityElementMinimum = nums.size()/ 2;

        for(int i = 0; i< nums.size(); i++){
            if(numCount.find(nums[i]) == numCount.end()){
                numCount[nums[i]] = 1;
            } else {
                numCount[nums[i]] += 1;
            }
        }

        for(auto entry: numCount){
            cout<< "key" << entry.first << ", value:" << entry.second<< endl; 
            if(entry.second > majorityElementMinimum) return entry.first;
        }

    return -1;

    }
};