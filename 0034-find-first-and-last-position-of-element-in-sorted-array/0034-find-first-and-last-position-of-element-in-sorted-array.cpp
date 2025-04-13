class Solution {
public:
    int findLeftIndex(int left, int right, vector<int>& nums, int target){
        int index = right; 
        while(left <= right){
            int m = (left + right)/2;

            if(nums[m] >= target){
                if(nums[m] == target) index = m;
                right = m -1;                
            } else {
                left = m + 1;
            }
        }

        return index;
    }

    int findRightIndex(int left, int right, vector<int>& nums, int target){
        int index = left; 
        while(left <= right){
            int m = (left + right)/2;

            if(nums[m] <= target){
                if(nums[m] == target) index = m;
                left = m + 1;                
            } else {
                right = m - 1;
            }
        }

        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1;
        int m;
        int leftIndex = -1, rightIndex = -1;
        while(left <= right){

            m = (left + right)/2;

            if(nums[m] == target){
                leftIndex = findLeftIndex(left, m, nums, target);
                rightIndex = findRightIndex(m, right, nums, target);
                break;
            }

            if(nums[m] < target){
                left = m + 1;
            } else if(nums[m] > target){
                right = m-1;
            }
            
        }

        return {leftIndex, rightIndex};
    }
};