class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } 
         
            else {
                if (stk.empty()) return false; // Stack should not be empty for a closing bracket
                char top = stk.top();
                stk.pop();
                // Ensure the current closing bracket matches the last opening bracket
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }
        // In the end, stack should be empty if parentheses are valid
        return stk.empty();
    }
};
