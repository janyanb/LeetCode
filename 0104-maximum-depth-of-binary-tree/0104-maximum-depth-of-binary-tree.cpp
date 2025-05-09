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
    int maxDepth(TreeNode* root) {

        function<int(TreeNode*)> dfs = [&](TreeNode *curr) -> int {
            if(!curr) return 0;
            
            int ldepth = dfs(curr->left);
            int rdepth = dfs(curr->right);


            return 1 + max(ldepth, rdepth);
        };

         int depth = dfs(root);

        return depth;
    }
};