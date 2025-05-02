class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> Q;               //type, container_type, comparator

        for(int num : nums){
            Q.push(num);

            if(Q.size() > k){
                Q.pop();
            }
        }

        return Q.top();
    } 
};