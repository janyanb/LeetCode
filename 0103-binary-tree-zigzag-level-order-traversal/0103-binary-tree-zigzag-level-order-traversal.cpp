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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        int count = 0;
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);

        while(!q.empty()){
            vector<int> lnodes;
            int len = q.size();
            for(int i = 0; i< len; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    lnodes.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(count%2==0){
                if(!lnodes.empty()) res.push_back(lnodes);
            }else{
                reverse(lnodes.begin(), lnodes.end());
                if(!lnodes.empty()) res.push_back(lnodes);
            }
            count++;
        }

        return res;
    }
};