class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int maxProd = nums[0];
        int currMin = nums[0]; //in case we encounter negative values

        for(int i =1; i< nums.size(); i++){
            if(nums[i] < 0){
                swap(currMax, currMin);    // currMin has minimum so far(negative), when multiplied by nums[i](also negative) will reverse the currMax
            };

            currMax = max(nums[i], nums[i] * currMax);
            currMin = min(nums[i], nums[i] * currMin);

            maxProd = max(currMax, maxProd);

        }


        return maxProd;
       /* int left = 0, right = 0;
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

        return result;*/

    }
};