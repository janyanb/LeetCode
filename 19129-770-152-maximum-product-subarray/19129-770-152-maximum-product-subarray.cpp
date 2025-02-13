class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto it = max_element(nums.begin(), nums.end());
        int result;
        if(it != nums.end()){
            result = *it;
        };
        int currMax = 1, currMin = 1;

        for(int n: nums){
            if(n == 0){
            currMax = 1, currMin = 1;
            continue;
            }
        int tmp = n*currMax;
        currMax = max({n, currMax * n, currMin*n});
        currMin = min({n, tmp, currMin*n});
        result = max(result, currMax);
        }
        return result; 
    }
};