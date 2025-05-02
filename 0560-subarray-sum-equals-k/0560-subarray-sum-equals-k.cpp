class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int,int> PrefixMap;

        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];

            if(sum == k) count++;

            if(PrefixMap.find(sum - k) != PrefixMap.end()){
                count += PrefixMap[sum -k];
            }
            PrefixMap[sum]++;
        }

        return count;
    }
};