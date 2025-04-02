class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> res;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum > target){
                right--;
            } else if(sum < target){
                left++;
            } else {
                res.push_back(left + 1);
                res.push_back(right + 1);
                break;
            }
        }
        return res;
    }
};