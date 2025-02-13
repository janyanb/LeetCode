class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       /* unordered_map<int,bool> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = true; //mark every number as the start of a sequence
        }

        for(int i = 0; i < nums.size(); i++){
            if(map.count(nums[i] -1) > 0){
                map[nums[i]] = false; //if a lesser number exists then nums[i] cannot be start of sequence 
            }
        }
    
        int Longestlen = 0;
        for(int i = 0; i< nums.size(); i++){
            int j = 0;
            if(map[nums[i]] == true){
                int count = 0;
                while(map.count(nums[i]+j) > 0){
                    j++;
                    count++;
                }
                Longestlen = max(Longestlen, count);
            }
        }
        return Longestlen; */

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        
        // Iterate over each unique number.
        for (int num : numSet) {
            // Check if it is the start of a sequence.
            // A number is a sequence start if there is no number that is one less than it.
            if (!numSet.count(num - 1)) {
                int current = num;
                int streak = 1;
                
                // Count how long the consecutive sequence is.
                while (numSet.count(current + 1)) {
                    current++;
                    streak++;
                }
                
                longest = max(longest, streak);
            }
        }
        
        return longest;

    }
};