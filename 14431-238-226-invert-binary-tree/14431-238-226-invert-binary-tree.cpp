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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        
        function<TreeNode*(TreeNode*)> rec = [&](TreeNode* curr) -> TreeNode* {
            if(!curr) return nullptr;

            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            rec(curr->left);
            rec(curr->right);

            return curr;
        };

        return rec(root);
    }
};