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
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);     
    }

    bool validate(TreeNode* node, TreeNode* lowest, TreeNode* highest) {
        if (!node) return true;
        
        if (lowest && node->val <= lowest->val) return false;            //all values in right subtree should be higher than the current node(lowest)
        if (highest && node->val >= highest->val) return false;           //all nodes in left subtree should be smaller than the current node(highest)
        
        return validate(node->left, lowest, node) && validate(node->right, node, highest);
}

};