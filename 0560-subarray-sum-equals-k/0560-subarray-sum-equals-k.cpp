class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int,int> PrefixMap;       //map must remember how many times prefix value has appeared, every position it has appeared can form a diff subarray with the current position(i).
        PrefixMap[0] = 1;

        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];

            if(PrefixMap.find(sum - k) != PrefixMap.end()){
                count += PrefixMap[sum -k];
            }
            PrefixMap[sum]++;
        }

        return count;
    }
};