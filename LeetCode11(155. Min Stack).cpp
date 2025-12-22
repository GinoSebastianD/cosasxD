class MinStack {
public:
    std::vector<int> pil;
    std::vector <int> min;
    MinStack() { 
        
    }

    void push(int val) {
        pil.push_back(val);
        
        if (min.empty() || val <= min.back())
        {
            min.push_back(val);
        }

    }

    void pop() {
        if (pil.back() == min.back())
            min.pop_back();
        pil.pop_back();
    }

    int top() {
        return pil.back();
    }

    int getMin() {
     
         return min.back();
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
