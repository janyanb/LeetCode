class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;     

        while(left <= right){     
            int m= (left + right)/2;

            if(target == nums[m]){
                return m;
            }

            if(nums[left] <= nums[m]){
                if(target<nums[left] || target > nums[m]){
                    left = m + 1;
                } else{
                 right = m-1;  
                }              
            } else {
                if(target > nums[right] || target < nums[m]){
                    right = m -1;
                } else {
                left = m + 1;  
                }             

            };
             
        }
        return -1;
    }
};





