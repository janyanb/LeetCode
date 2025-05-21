class Solution {
public:
    int hammingWeight(int n) {
        uint32_t temp;
        int count = 0;
        for(int i = 0; i<= 30; i++){
            temp = (n >> i) & 1;
            if(temp == 1) count++;
        }

        return count;        
        
    }
};