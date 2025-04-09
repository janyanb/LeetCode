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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderIndex;

        for(int i = 0; i< inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }

        TreeNode *root = constructTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() -1, inorderIndex);

        return root;
        
    }

    TreeNode* constructTree(vector<int>& postorder, int postorderStart, int postorderEnd, vector<int>& inorder, int inorderStart, int inorderEnd, unordered_map<int,int>& inorderIndex){

        if(inorderStart > inorderEnd || postorderStart> postorderEnd) return nullptr;

        TreeNode *root = new TreeNode(postorder[postorderEnd]);

        int rootIndex = inorderIndex[root->val];
        int leftTreeSize = rootIndex - inorderStart; 

        root->left = constructTree(postorder, postorderStart, postorderStart + leftTreeSize -1, inorder, inorderStart, rootIndex-1, inorderIndex);
        root->right= constructTree(postorder, postorderStart + leftTreeSize, postorderEnd -1, inorder, rootIndex+1, inorderEnd, inorderIndex);

        return root;
    };
};