class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        string concatenated = s + s;
        // Check if goal is a substring of concatenated
        if (concatenated.find(goal) != string::npos) {
// string::npos is a special constant in C++ that represents a value that indicates "not found." It's defined within the std::string class and is typically used when performing operations like searching for a substring in a string.
            return true; 
        } else {
            return false;
        }
    }
};
