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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, long long>> Q;
        Q.push({root, 0});
        int maxWidth = -1e9;

        while(!Q.empty()){
            vector<int> levelNodes;
            int len = Q.size();
            long long minNum = 1e9;
            for(int i = 0; i< len; i++){
                TreeNode* node = Q.front().first;
                long long num = Q.front().second;
                Q.pop();
                levelNodes.push_back(num);
                minNum = min(num, minNum);
                long long j = num - minNum;
                if(node->left)Q.push({node->left, (2*j) + 1});
                if(node->right)Q.push({node->right, (2*j) + 2});
            }
            maxWidth = max(maxWidth, (levelNodes[len -1] - levelNodes[0]) + 1);
        }


        return maxWidth;    
    }
};