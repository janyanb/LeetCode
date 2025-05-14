/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    //wrong Intuition
    // void getMin(TreeNode* root, int &minDiff){
    //     if(!root) return;
        
    //     int leftMin = INT_MAX, rightMin = INT_MAX;
    //     if(root->left != nullptr){
    //         leftMin = abs(root->val - root->left->val);
    //     }
    //     if(root->right != nullptr){
    //         rightMin = abs(root->val - root->right->val);
    //     }

    //     minDiff = min(minDiff, min(leftMin, rightMin));

    //     getMin(root->left, minDiff);
    //     getMin(root->right, minDiff);
    // }

    void InOrder(TreeNode* root, vector<int>& sorted){
        if(!root) return;

        InOrder(root->left, sorted);
        sorted.push_back(root->val);
        InOrder(root->right, sorted);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> sorted;

        InOrder(root, sorted);

        int minDiff = INT_MAX;
        for(int i = 1; i< sorted.size(); i++){
            minDiff = min(minDiff, abs(sorted[i-1] - sorted[i]));
        }

        return minDiff;

    }
};