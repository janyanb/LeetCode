class MinStack {
private: 
    vector<pair<int,int>> stack; 
    int minimum = INT_MAX;
public:
    MinStack() {
    }
    
    void push(int val) {        
        if (stack.empty()) {
            stack.push_back({val,val});
        } else {
            int currMin = stack.back().second;
            stack.push_back({val, min(val,currMin)});
        }
    
    }
    
    void pop() {
        // if(stack.back().first == minimum && stack.size() > 2) {
        //     int num = stack.size() - 2;
        //     minimum = stack[num].second;
        // }
        stack.pop_back();
        // if(stack.empty()) minimum = INT_MAX;
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
       return stack.back().second;
               
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */