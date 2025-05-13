/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> Q;
        Q.push(root);
        while(Q.size()!= 0){
            int len = Q.size();
            for(int i = 0; i< len; i++){
                Node* n1 = Q.front();
                Q.pop();
                if(n1 != nullptr){
                    if(i == len -1){
                        n1-> next = nullptr;
                    } else {
                        n1 -> next = Q.front();
                    }
                    if(n1->left != nullptr) Q.push(n1->left);
                    if(n1->right != nullptr) Q.push(n1->right);
                }
            }
        }

        return root;
    }
};