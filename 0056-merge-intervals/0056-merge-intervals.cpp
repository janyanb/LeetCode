class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int minNum;
        int maxNum;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        int i;
        for(i = 0; i< intervals.size() - 1; i++){
            if(intervals[i][1] >= intervals[i+1][0]){
                minNum = min(intervals[i][0], intervals[i+1][0]);
                maxNum = max(intervals[i][1], intervals[i+1][1]);
                intervals[i+1][0] = minNum;
                intervals[i+1][1] = maxNum;
            } else {
                res.push_back(intervals[i]);
            }
        }
        res.push_back(intervals[i]);

        return res;
    }
};