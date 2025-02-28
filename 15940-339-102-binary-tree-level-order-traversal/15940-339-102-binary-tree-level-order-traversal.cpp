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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size() != 0){
           int len = q.size();
           vector<int> lnodes;
           for(int i = 0; i< len; i++){
            TreeNode* nval = q.front();
            q.pop();
            if(nval){
                lnodes.push_back(nval->val);
                q.push(nval->left);
                q.push(nval->right);
            };
           };
           if(!lnodes.empty()){
            result.push_back(lnodes); 
            }
        };
        return result;        
    }
};