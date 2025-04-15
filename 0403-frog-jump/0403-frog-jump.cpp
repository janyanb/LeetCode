class Solution {
private: vector<vector<int>> dp;
public:    
    unordered_map<int, int> stonesMap;
    Solution(): dp(2000, vector<int>(2000, -1)){}
    

    int canReachEnd(int i, int k, vector<int>& stones){
        if(i == stones.size() - 1) return true;

        if(dp[i][k] != -1) return dp[i][k];

        bool kjumps = false, km1jumps = false, kp1jumps = false;

        if(stonesMap.find(stones[i]+ k) != stonesMap.end()){
            kjumps = canReachEnd(stonesMap[stones[i] + k], k, stones);
        }

        if(k > 1 && stonesMap.find(stones[i] + (k - 1)) != stonesMap.end()){
            km1jumps = canReachEnd(stonesMap[stones[i] + (k - 1)], k-1, stones);
        }

        if(stonesMap.find(stones[i] + (k + 1)) != stonesMap.end()){
            kp1jumps = canReachEnd(stonesMap[stones[i] + (k + 1)], k+1, stones);
        }

        return dp[i][k] = kjumps || km1jumps || kp1jumps;
    }

    bool canCross(vector<int>& stones) {

    if(stones[1] - stones[0] != 1) return false;

        for(int i = 0; i< stones.size(); i++){
            stonesMap[stones[i]] = i;
        }

    return canReachEnd(1,1, stones);
    }
};