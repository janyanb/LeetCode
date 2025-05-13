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
    int findNodes(TreeNode* root){
        if(!root) return 0;

        int left = findNodes(root-> left);
        int right = findNodes(root->right);

        return left + right + 1;
    }
    int countNodes(TreeNode* root) {
        return findNodes(root);
    }
};