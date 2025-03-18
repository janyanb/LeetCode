class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m - 1;
        int j = n -1;
        for(int i = (m+n-1); i>=0; i--){
            if(j < 0) {
                break;
            }
            if(k < 0){
                nums1[i] = nums2[j];
                j--;
            } else if (nums1[k] < nums2[j]){
                nums1[i] = nums2[j];
                j--;
            } else if (nums1[k] > nums2[j]){
                nums1[i] = nums1[k];
                k--;
            } else {
                nums1[i] = nums1[k];
                j--;
            }          


        }
        
    }
};