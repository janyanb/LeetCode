class RSet{
public:
    unordered_map<int,int> numToIndex;
    vector<int> RandomElements;

    RSet(): numToIndex{}, RandomElements{}{}

    bool isExist(int val){
        if(numToIndex.find(val) == numToIndex.end()){
            return false;
        }
        return true;
    }

    void newElement(int num , int index){
        numToIndex[num] = index;
    }

    void Erase(int val){
        int last = RandomElements.back();
        int index = numToIndex[val];

        //replace val to remove with last element, and update new index of last
        RandomElements[index] = last;
        numToIndex[last] = index;

        RandomElements.pop_back();
        numToIndex.erase(val);
    }

    void addElement(int val){
        RandomElements.push_back(val);
    }

    int getSize(){
        return numToIndex.size();            //iteratively maintains the size of vector
    }

    int getValue(int index){
        return RandomElements[index];
    }

};

class RandomizedSet {
private: RSet* rset; int counter = 0;
public:
    RandomizedSet() {
        rset = new RSet();
    }
    
    bool insert(int val) {
        if(!rset->isExist(val)){
            rset->addElement(val);
            rset->newElement(val, counter);
            counter++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(rset->isExist(val)){
            rset->Erase(val);
            counter--;
            return true;
        }
        return false;        
    }
    
    int getRandom() {
        int size = rset->getSize();
        int index= rand() % size;

        return rset->getValue(index);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */