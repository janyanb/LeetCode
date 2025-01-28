/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> clones;

        function<Node*(Node*)> dfs = [&](Node* current){
            if(clones.find(current) != clones.end()){
                return clones[current];
            }

            Node* clone = new Node(current->val);
            clones[current] = clone;

            for (Node* nei: current-> neighbors){
                clone->neighbors.push_back(dfs(nei));
            }
            return clone;
        };
        return dfs(node);
        
    }
};