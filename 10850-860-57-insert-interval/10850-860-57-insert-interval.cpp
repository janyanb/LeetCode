class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> updatedInterval; 

        for(int i = 0; i < intervals.size(); i++){
            if(newInterval[1] < intervals[i][0]){
                updatedInterval.push_back(newInterval);
                updatedInterval.insert(updatedInterval.end(), intervals.begin() + i, intervals.end());
                return updatedInterval;
            } else if(newInterval[0] > intervals[i][1]){
                updatedInterval.push_back(intervals[i]);
            } else {
                int minNum = min(newInterval[0], intervals[i][0]);
                int maxNum = max(newInterval[1], intervals[i][1]);
                newInterval[0] = minNum;
                newInterval[1] = maxNum; 
            }
        }

        updatedInterval.push_back(newInterval);
        return updatedInterval;
    }
};