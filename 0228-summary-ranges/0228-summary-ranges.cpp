class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if(nums.empty()) return ranges;
        if(nums.size() == 1) {
           ranges.push_back(to_string(nums[0]));
           return ranges;
        }
        int minNum = INT_MAX, maxNum = nums[0], i = 0;
        string range;
        while(i< nums.size()){
            while(i+1< nums.size() && nums[i+1] == nums[i] + 1){
                minNum = min(nums[i], minNum);
                if (range.empty()) range += to_string(minNum) + "->";                
                i++;
            } 
            maxNum = max(nums[i], maxNum);
            range+= to_string(maxNum);
            ranges.push_back(range);
            range.clear();
            minNum = INT_MAX;
            i++;
        }

        return ranges;
    }
};