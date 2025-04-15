class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> prefixMap;
        long long sum = 0;
        int maxlen = 0;
        for(int i = 0; i< nums.size(); i++){
            sum += nums[i];                     //finding sum until i
            if(sum == k) maxlen = i + 1;       //if with new i, sum == k
            

            int comp = sum - k;                             
            if(prefixMap.find(comp) != prefixMap.end()){       //checking if the compliment of sum - k exists
                int len = i - prefixMap[comp];               //compute the length of the new subarray
                maxlen = max(maxlen, len);
            }


            if(prefixMap.find(sum) == prefixMap.end()) prefixMap[sum] = i;    //if there already exists a complement, do not overwrite to maintain maximum subarray.            
        }

        return maxlen;
    }
};