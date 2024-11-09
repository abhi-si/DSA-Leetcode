class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        
        string result;
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < s.size(); j += cycleLen) {
                result += s[j + i];
                // Add the diagonal character in the cycle (except for the first and last rows)
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.size())
                    result += s[j + cycleLen - i];
            }
        }
        return result;
    }
};
