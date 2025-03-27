class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()% k != 0)  return false; 
        map<int,int> numMap;               //constructor initializes values to 0.
        vector<vector<int>> numSet;
        for(int i = 0; i< nums.size(); i++){
            numMap[nums[i]] += 1; 
        };

        vector<int> set;
        while(!numMap.empty()){
            auto smallpair = numMap.begin();
            int smallest = smallpair->first;

            if(smallpair->second == 0) continue;
            int currnum = smallest;
            for(int i = 0; i <k ; i++){            

                if(numMap.find(currnum) == numMap.end()){
                    return false;
                }
                numMap[currnum]--;
                if(numMap[currnum] == 0) numMap.erase(currnum);
                currnum ++;
            }
 
        }

        return true;

    }
};