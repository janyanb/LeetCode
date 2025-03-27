class Solution {
public:
    int hIndex(vector<int>& citations) {
        //sort vector in descending order
        //check if num[i] papers have at least num[i] citations

        int h=0;
        sort(citations.begin(), citations.end(), greater<int>());          //sort in descending order
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] >= i + 1){  //ith paper has more than or equal to citations[i] papers with atleast citation[i] citations.
                h = i + 1;  
            } else {
                break;
            }
        }
        return h;
    }
};