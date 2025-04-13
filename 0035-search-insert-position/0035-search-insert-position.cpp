class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1, m;
        if(target > nums[right]) return nums.size();
        if(target < nums[left]) return 0;

        while(left <= right){
            if(right - left == 1 || right == left){
                if(target > nums[right]) return right + 1;
                if(target > nums[left]) return left +1;

                return left;
            }

            m = (left + right) / 2;


            if(nums[m] == target) return m;

            if(nums[m] < target){
                left = m +1;
            } else if(nums[m] > target){
                right = m -1;
            }

        }

        return 0;
    }
};