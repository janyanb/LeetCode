class Solution {
public:
    int hammingWeight(int n) {
        vector<int> binaryN;
        while(n!= 0){
            if(n%2 == 1){
                binaryN.push_back(1);
            };
            n = n/2;     
        }        

        return binaryN.size();        //reverse(binaryN.begin(), binaryN.end()) = binary rep of n
        
    }
};