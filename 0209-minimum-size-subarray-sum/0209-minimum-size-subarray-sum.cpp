class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total = 0, minLength = nums.size(), length =0;

        int left = 0, right;
        for(right = 0; right< nums.size(); right++){
            total += nums[right];

            //sliding window problem, you can always get the window size by doing right - left + 1
            while(total >= target){
                minLength = min(right - left + 1, minLength);
                total -= nums[left];
                left++;
            }

        }


        return (left == 0)?0: minLength;   //if minLentgth = nums.size() that means a solution was never found
    }
};