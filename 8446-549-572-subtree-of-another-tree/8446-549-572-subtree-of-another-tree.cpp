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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        //travers through subtree and maintree together
        function<bool(TreeNode*, TreeNode*)> rec = [&](TreeNode* tnode, TreeNode* snode){
            if(!tnode && !snode) return true;
            if(!tnode || !snode) return false;
            if(tnode->val != snode->val) return false;
            return rec(tnode->left, snode->left) && rec(tnode->right, snode->right);
        };

        //travserse through maintree
        function<bool(TreeNode*, TreeNode*)> mainf = [&](TreeNode* t1, TreeNode* t2){
            if(!t1) return false;
            if(rec(t1,t2)) return true;  //if both trees are same

            return mainf(t1->left, t2) || mainf(t1->right, t2);
        };

        return mainf(root, subRoot);

    }
};