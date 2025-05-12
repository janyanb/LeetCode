class Node{
public:
    vector<Node*> nextLetter;
    bool flag = false;

    Node(): nextLetter(26, nullptr){};

    bool isExist(char letter){
        return (nextLetter[letter - 'a']);
    }

    void put(char letter, Node* node){
        nextLetter[letter - 'a'] = node;
    }

    Node* next(char letter){
        return nextLetter[letter - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool flagvalue(){
        return flag;
    }

};

class WordDictionary {
private: Node* root;
public:
    WordDictionary() {
        root = new Node(); 
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0; i< word.size(); i++){
            if(!node->isExist(word[i])){
                node->put(word[i], new Node);
            }
            node = node->next(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return searchHelper(root, word, 0);
    }

private:
    bool searchHelper(Node* node, string word, int index){
        
        //if(!node) return false;

        if(index == word.size()) return node->flagvalue();

        if(word[index] == '.'){
            for(char i = 'a'; i <= 'z'; i++){
                if(node->isExist(i)){
                    if(searchHelper(node->next(i), word, index + 1)){
                        return true;
                    }
                }
            }
            return false;
        } else {
            if(node->isExist(word[index])){
                return searchHelper(node->next(word[index]), word, index + 1);
            }
            return false;            
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */