class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
    }
    
    void push(int val) {
        pair<int, int> p;
        p.first = val;
        int min = 0;
        if(st.empty() || (!st.empty() && val < st.top().second)){
            min = val;
        } else {
            min = st.top().second;
        }
        p.second = min;
        st.push(p);
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return 0;
        } else {
            return st.top().first;
        }
    }
    
    int getMin() {
        return st.top().second;
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