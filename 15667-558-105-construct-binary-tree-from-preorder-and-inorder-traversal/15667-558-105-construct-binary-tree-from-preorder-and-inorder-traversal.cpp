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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inorderIndex;

        for(int i = 0; i < inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        };

        TreeNode* root = constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderIndex);

        return root;        
    }
    TreeNode* constructTree(vector<int>& preorder, int preorderStart, int preorderEnd, vector<int>& inorder, int inorderStart, 
    int inorderEnd, map<int,int>& inorderIndex){

        if(preorderStart > preorderEnd || inorderStart > inorderEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preorderStart]);

        //find index of root in map and get number of elements to left of index(leftsubtree);
        int rootIndex = inorderIndex[root->val];
        int numLeftTree = rootIndex - inorderStart;  //size of left subtree

        root->left = constructTree(preorder, preorderStart + 1, preorderStart + numLeftTree, inorder, inorderStart, rootIndex - 1, inorderIndex);
        root->right = constructTree(preorder, preorderStart + numLeftTree + 1, preorderEnd, inorder, rootIndex + 1, inorderEnd, inorderIndex);

        return root;
    };
};