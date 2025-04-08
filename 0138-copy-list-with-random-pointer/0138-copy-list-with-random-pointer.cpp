/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> clones;

        function<Node*(Node*)> rec = [&](Node* curr)-> Node*{
            if(!curr) return nullptr;
            if(clones.find(curr) != clones.end()) return clones[curr];

            Node* clone = new Node(curr->val);
            clones[curr] = clone;

            clone->next = rec(curr->next);
            clone->random = rec(curr->random);

            return clone;
        };

        return rec(head);
        
    }
};