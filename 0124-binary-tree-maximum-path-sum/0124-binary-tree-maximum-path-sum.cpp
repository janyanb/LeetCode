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
    int findPath(TreeNode* root, int &maxP){
        if(!root) return 0;

        int left = max(0,findPath(root->left, maxP));
        int right = max(0, findPath(root->right, maxP));

        maxP= max(maxP, left + right + root->val);

        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxP = INT_MIN;
        return max(findPath(root, maxP),maxP);      //pass maxP by ref;
    }
};