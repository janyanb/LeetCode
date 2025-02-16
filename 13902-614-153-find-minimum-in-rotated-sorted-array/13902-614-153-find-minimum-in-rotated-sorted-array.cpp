class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int left = 0, right = nums.size() -1;
        int res= nums[0];

        while(left <= right){
            if(nums[left] < nums[right]){
                res = min(res,nums[left]);
                break;
            };

            int m = (left + right) / 2;
            res = min(res, nums[m]);

            if(nums[m] >= nums[left]){
                left = m +1;
            } else {
                right = m -1;
            }     

        }
    return res;
    }

};