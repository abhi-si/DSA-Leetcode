class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;
        int length = 0;
        
        // Skip trailing spaces
        while (n >= 0 && s[n] == ' ') {
            n--;
        }
        
        // Count the length of the last word
        while (n >= 0 && s[n] != ' ') {
            length++;
            n--;
        }
        
        return length;
    }
};
