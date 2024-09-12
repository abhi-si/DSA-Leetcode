class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;  // To track the depth of parentheses
        
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    result += c;  // Only add '(' if it's not the outermost
                }
                depth++;  // Increase depth for '('
            } 
            else {
                depth--;  // Decrease depth for ')'
                if (depth > 0) {
                    result += c;  // Only add ')' if it's not the outermost
                }
            }
        }
        
        return result;
    }
};
