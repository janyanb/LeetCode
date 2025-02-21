class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> postfix(n);
        vector<int> returnVec(n);
        int curr = 1;

        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                prefix[i] = 1;
            } else {
            curr *= nums[i-1];
            prefix[i] = curr;
            }
        }

        curr = 1;
        for(int j = nums.size() - 1; j >=0; j--){
            if(j == nums.size()-1){
                postfix[j] = 1;
            } else {
            curr *=  nums[j+1];
            postfix[j] = curr;
            }
        }

        for(int k = 0; k< nums.size(); k++){
            returnVec[k] = prefix[k] * postfix[k]; 
        };

        return returnVec;
    }
};