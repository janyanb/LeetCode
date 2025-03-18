class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0; //last valid unique index
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[j]){
                count ++;
                if(count <= 2){
                    j++;
                    nums[j] = nums[i];
                }
            } else {
                j++;
                nums[j] = nums[i];
                count = 1;
            }
        }
        return j + 1;
    }
};