class Node{
public:
    vector<Node*> nextNode;
    bool flag = false;

    Node():nextNode(26,nullptr){};    

    bool isExist(char letter){
        return (nextNode[letter - 'a']);
    }

    void put(char letter, Node *node){
        nextNode[letter - 'a'] = node;
    }

    Node* next(char letter){
        return nextNode[letter - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool flagvalue(){
        return flag;
    }

};

class Trie {
private: Node* root;
public:
    Trie() {
       root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i = 0 ; i< word.size(); i++){
            if(!node->isExist(word[i])){        //check if char exists on existing Node
                node->put(word[i], new Node); 
            }
            node = node->next(word[i]);            
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->isExist(word[i])){
                return false;
            }
            node = node->next(word[i]);
        }
        return node->flagvalue();        
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i =0; i<prefix.size(); i++){
            if(!node->isExist(prefix[i])){
                return false;
            }
            node = node->next(prefix[i]);
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */