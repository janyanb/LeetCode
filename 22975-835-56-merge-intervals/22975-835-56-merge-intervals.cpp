class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      /*  int n = intervals.size();
        for(int i = 0; i < n; i++){
            bool swapped = false;
            for(int j = 0; j < n - i - 1 ; j++){                              //-1 because we will compare j+1 in the loop
                if(intervals[j+1][0] < intervals[j][0]){                      //bubble sort
                    swap(intervals[j], intervals[j+1]);
                    swapped = true;     
                }
            };
            if(!swapped) break;            
        }*/

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> mergedIntervals;
        int i;
        for(i =0; i< n -1 ;i++){                                             // -1 because we will compare i+1 in loop                             
            if(intervals[i+1][0] <= intervals[i][1]){
                int minNum = min(intervals[i][0], intervals[i+1][0]);
                int maxNum = max(intervals[i][1], intervals[i+1][1]);
                intervals[i+1][0] = minNum;
                intervals[i+1][1] = maxNum;
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
        }
        
        mergedIntervals.push_back(intervals[n-1]);
        return mergedIntervals;
    }
};

