// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    
    MinStack() {
        s = {};
    }
    
    void push(int val) {
        if (s.empty()) s.push({val, val});
        else s.push({val, min(val, s.top().second)});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
    
private:
    stack<pair<int, int>> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */