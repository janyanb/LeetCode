class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        map<int,int> LowestSum;
        int sum;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i< nums.size(); i++){
            int left = i+1, right = nums.size() -1;
            while(left<right){
                sum = nums[i] + nums[left] + nums[right];
                if(sum < target){
                    left++;
                } else if(sum > target){
                    right--;
                } else if(sum == target){
                    return target;
                }

                int diff = abs(target - sum);
                LowestSum[diff] = sum; 
            }

        }

        return LowestSum.begin()->second;
    }
};