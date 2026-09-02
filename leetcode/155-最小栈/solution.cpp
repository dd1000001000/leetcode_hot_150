class MinStack {
private:
    stack<pair<int, int>> stk;

public:
    MinStack() {
    }
    
    void push(int value) {
        int minimum = stk.empty() ? value : min(value, stk.top().second);
        stk.push({value, minimum});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
