class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        //check if actual end index is reachable from ith position
        for(int i = nums.size() -1; i >=0; i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }
        return goal == 0;
    }
};