class Solution {
public:
    int climbStairs(int n) {
        // if(n <= 1) return 1;

        // int left = climbStairs(n -1);
        // int right = climbStairs(n -2);

        // return left + right;

        int prev1 = 1, prev2 = 1;
        int curr = 1;
        for(int i = 2; i <= n ; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};