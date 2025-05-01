class Solution { 
private: vector<int> prefix;
public:
    Solution(vector<int>& w) {
        int curr = 0;
        for(int i = 0; i< w.size(); i++){
            curr += w[i];
            prefix.push_back(curr);
        }
    }

    int searchInd(int num){
        int start = 0, end = prefix.size() - 1, mid;

        while(start < end){
            mid = (start + end)/2;

            if(num < prefix[mid]){
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
    
    int pickIndex() {
        int ind = rand() % prefix.back();

        return searchInd(ind);

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */