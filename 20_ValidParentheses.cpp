// https://leetcode.com/problems/valid-parentheses/submissions/

class Solution {
public:
    // O(n) time, O(n) space
    bool isValid(string s) {
        stack<char> chars;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                chars.push(c);
            }
            else if ((c == ')' && !chars.empty() && chars.top() == '(') || 
                     (c == '}' && !chars.empty() && chars.top() == '{') ||
                     (c == ']' && !chars.empty() && chars.top() == '[')) {
                chars.pop();
            } else {
                return false;
            }
        }
        return chars.empty();
    }
};
