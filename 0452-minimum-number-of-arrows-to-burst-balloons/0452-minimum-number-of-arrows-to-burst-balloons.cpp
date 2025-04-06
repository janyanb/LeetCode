class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        vector<vector<int>> newIntervals;

        //sorts by end
        sort(points.begin(), points.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int commonPoint = points[0][1];
        int numArrows = 1;
        for(int i = 1; i< points.size(); i++){
            if(commonPoint < points[i][0]){
                numArrows++;
                commonPoint = points[i][1];
            }
        }

        return numArrows;
    }
};