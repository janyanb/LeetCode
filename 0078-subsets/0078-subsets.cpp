class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> Subsequence;
        vector<int> elements;

        function<void(int,vector<int>)> rec = [&](int index, vector<int> Subseq) -> void {
            if(index >= nums.size()){
                Subsequence.push_back(Subseq);
                return;
            }

            //take the index in subseq
            Subseq.push_back(nums[index]);
            rec(index + 1, Subseq);

            //do not take the index in subseq
            Subseq.pop_back();
            rec(index +1, Subseq);
        };

        rec(0, elements);
        return Subsequence;        
    }
};