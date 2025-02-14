class Solution {
public:
    int maxProduct(vector<int>& nums) {

        //O(n) approach usind DP
        /*auto it = max_element(nums.begin(), nums.end());
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
        return result;*/

        //O (n^2) using sliding window
        int left = 0, right = 0;
        int result, prod = 1;
        auto maximum = max_element(nums.begin(), nums.end());
        if(maximum != nums.end()){
            result = *maximum;
        };

        while(right < nums.size()){
            for(int curr = left; curr <= right; curr++){
                prod *= nums[curr];
            }
            result = max(result, prod);
            right++;
            prod = 1;
            if(right == nums.size()){
                left ++;
                right = left;
            }
        }

        return result;

    }
};
