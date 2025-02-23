class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int count = 0;

        for(int i = 0; i < n - 1; i++){
            if(intervals[i+1][0] < intervals[i][1]){
                count ++;
                if(intervals[i+1][1] > intervals[i][1]){
                    intervals[i+1] = intervals[i];
                };                
            };
        };
        return count;
    }
};