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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;

        function<vector<int>(TreeNode*)> postordertrav = [&](TreeNode* node){
            if(!node) return postorder;

            postordertrav(node->left);
            postordertrav(node->right);
            postorder.push_back(node->val);

            return postorder;
        };

        return postordertrav(root);
    }
};