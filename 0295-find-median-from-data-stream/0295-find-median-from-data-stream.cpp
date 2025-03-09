class MedianFinder {
public:
    vector<int> small;  //maxheap
    vector<int> large;   //minheap

    MedianFinder() {
    }
    
    void addNum(int num) {
        small.push_back(num);                           //push num by default into small
        push_heap(small.begin(),small.end());

        //check if the order is wrong(some elements in large vector are smaller that largest element of small)
        if(!small.empty() && !large.empty() && small[0] > large[0]){
            pop_heap(small.begin(), small.end());     //moves largest to end
            int lnum = small.back();          //get largest element
            small.pop_back();                 //pops largest

            large.push_back(lnum);
            push_heap(large.begin(), large.end(), greater<int>());            
        }

        //check for uneven size
        if(small.size() > large.size() + 1){
            pop_heap(small.begin(), small.end());
            int lnum = small.back();
            small.pop_back();

            large.push_back(lnum);
            push_heap(large.begin(), large.end(), greater<int>());
        } else if(large.size() > small.size() + 1){
            pop_heap(large.begin(), large.end(), greater<int>());
            int snum = large.back();
            large.pop_back();

            small.push_back(snum);
            push_heap(small.begin(), small.end());
        }        
    }
    
    double findMedian() {
        if(small.size() > large.size()) return small[0];
        if(large.size() > small.size()) return large[0];

        float med = (small[0] + large[0]) / 2.0;
        return med;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */