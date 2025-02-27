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

        int maxd = 0;

        function<int(TreeNode*, int)> dfs = [&](TreeNode *curr, int depth) -> int {
            if(!curr) return depth -1;
            
            int ldepth = dfs(curr->left, depth +1);
            int rdepth = dfs(curr->right, depth +1);

            maxd = max(ldepth, rdepth);

            return maxd;
        };

         int depth = dfs(root, 1);

        return depth;
    }
};