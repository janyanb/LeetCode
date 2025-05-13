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
class BSTIterator {
private: stack<TreeNode*> path;
public:
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    
    int next() {
        TreeNode* node = path.top();
        path.pop();
        pushNodes(node->right);
        return node-> val;
    }
    
    bool hasNext() {
        return (!path.empty());
    }
private:
    void pushNodes(TreeNode* root){
        if(!root) return;

        path.push(root);
        pushNodes(root->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */