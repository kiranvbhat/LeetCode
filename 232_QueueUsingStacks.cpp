// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> enqueue;
    stack<int> dequeue;
    MyQueue() {}
    
    void push(int x) {
        if (enqueue.empty()) {    // only switch stacks when necessary
            stackSwitch();
        }
        enqueue.push(x);
    }
    
    int pop() {
        if (dequeue.empty()) {
            stackSwitch();
        }
        int top = dequeue.top();
        dequeue.pop();
        return top;
    }
    
    int peek() {
        if (dequeue.empty()) {
            stackSwitch();
        }
        return dequeue.top();
    }
    
    bool empty() {
        return enqueue.empty() && dequeue.empty();
    }

private:
    void stackSwitch() {
        if (dequeue.empty()) {
            while (!enqueue.empty()) {
                int temp = enqueue.top();
                dequeue.push(temp);
                enqueue.pop();
            }
        }
        
        else if (enqueue.empty()) {
            while (!dequeue.empty()) {
                int temp = dequeue.top();
                enqueue.push(temp);
                dequeue.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
