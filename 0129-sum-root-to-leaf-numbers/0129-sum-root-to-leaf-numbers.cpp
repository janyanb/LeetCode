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
    int findSum(TreeNode* root, int dig){
        if(!root) return 0;

        dig = dig * 10 + root -> val;  //the curr nodes dig will be the same, it will be unaffected by the numbers added after this. 

        if(!root->left && !root-> right){
            return dig;
        }

       return findSum(root->left, dig) + findSum(root->right, dig);
    }

    int sumNumbers(TreeNode* root) {
        return findSum(root, 0);
    }
};