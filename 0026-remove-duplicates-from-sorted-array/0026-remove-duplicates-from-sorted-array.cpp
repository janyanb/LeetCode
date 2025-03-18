class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        int j = 0; //pointer to last unique element
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];       //assign the next unique element to the jth index
            }

        }

        return j + 1;
        
    }
};