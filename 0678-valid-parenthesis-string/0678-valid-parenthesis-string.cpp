class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0; 
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                minOpen++;
                maxOpen++;
            } else if (s[i] == ')') {
                minOpen--;
                maxOpen--;
            } else { // s[i] == '*'
                minOpen--;  // Consider '*' as ')'
                maxOpen++;  // Consider '*' as '('
            }

            if (maxOpen < 0) {
                return false;
            }
            
            if (minOpen < 0) {
                minOpen = 0;
            }
        }
        
        // If minOpen is 0 at the end, the string is valid
        return minOpen == 0;
    }
};

// private:
//     bool check(const string& s, int ind, int cnt) {
//         if (cnt < 0) return false; // Too many closing brackets
//         if (ind == s.size()) return cnt == 0; // All characters processed, check if valid
        
//         if (s[ind] == '(') {
//             return check(s, ind + 1, cnt + 1);
//         } else if (s[ind] == ')') {
//             return check(s, ind + 1, cnt - 1);
//         } else {
//             // The character is '*', it can be '(', ')' or empty
//             return check(s, ind + 1, cnt + 1) || // Consider '*' as '('
//                    check(s, ind + 1, cnt - 1) || // Consider '*' as ')'
//                    check(s, ind + 1, cnt);        // Consider '*' as empty
//         }
//     }
