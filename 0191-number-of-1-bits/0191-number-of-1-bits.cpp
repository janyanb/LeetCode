class Solution {
public:
    int hammingWeight(int n) {
        vector<int> binaryN;
        while(n!= 1){
            if(n%2 == 1){
                binaryN.push_back(1);
            } else binaryN.push_back(0);
            n = n/2;     
        }
        int hW = count(binaryN.begin(), binaryN.end(), 1);

        return hW + 1;       //reverse(binaryN.begin(), binaryN.end()) = binary rep of n
        
    }
};