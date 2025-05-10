class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freqIndex(nums.size() + 1, vector<int>());       //size + 1-> if all the elements in the array are same

        sort(nums.begin(), nums.end());

        //count as index, n as value
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){          //if repeating adjacent elements continue
                continue;
            }

            int index = count(nums.begin(), nums.end(), nums[i]);      //count number of occurances 
            freqIndex[index].push_back(nums[i]);                       //freq of num is index
        }

        vector<int> result;
        for(int i = freqIndex.size() - 1; i >= 0 ; i--){
            for(int j = 0; j < freqIndex[i].size(); j++){
                result.push_back(freqIndex[i][j]);
                k--;
                if(k == 0) return result;
            }
        };

    return result;  
    }
};