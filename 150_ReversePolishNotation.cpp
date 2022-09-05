// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    // returns true if s is an operator
    bool isOp(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
    
    int compute(int a, string op, int b) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        return 999; // if invalid op provided
    }
    
    // O(n) time, O(n) space
    int evalRPN(vector<string>& tokens) {
        // edge case
        if (tokens.size() < 3) {
            return stoi(tokens[0]);
        }
        
        stack<int> s;
        for (string token : tokens) {
            if (isOp(token)) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int soFar = compute(a, token, b);     // e.g. a + b
                s.push(soFar);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
