class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return true;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        for(int i = 1; i< intervals.size(); i++){
            if(intervals[i][0] < intervals[i-1][1]) return false;
        }

        return true;
    }
};