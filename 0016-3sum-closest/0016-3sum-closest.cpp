class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // map<int,int> LowestSum;        
        int sum;
        sort(nums.begin(), nums.end());
        int LowestSum = nums[1] + nums[2] + nums[3];
        int Smallestdiff = INT_MAX;

        
        for(int i = 0; i< nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
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

                
                // LowestSum[diff] = sum; 
                int diff = abs(target - sum);
                if(diff < Smallestdiff){
                    Smallestdiff = diff;
                    LowestSum = sum;
                }
            }

        }

        return LowestSum;
    }
};