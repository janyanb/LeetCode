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
    bool hasSum(TreeNode* root, int target, int total){
        if(!root) return false;

        total += root->val;

        if(!root->left && !root->right) return total == target;

        bool left = hasSum(root->left, target, total);
        bool right = hasSum(root->right, target, total);



        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return hasSum(root, targetSum, 0);
    }
};