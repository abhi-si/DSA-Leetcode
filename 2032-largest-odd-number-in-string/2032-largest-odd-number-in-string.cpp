class Solution {
public:
    string largestOddNumber(string num) {
        // Iterate over the string from the last character to the first
        for (int i = num.size() - 1; i >= 0; i--) {
            // Check if the current digit is odd
            
//In the expression (num[i] - '0'), we are converting a character digit (such as '0', '1', '2', etc.) into its corresponding integer value.
            if ((num[i] - '0') % 2 != 0) {
                // Return the substring from the start to the current position (inclusive)
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit is found, return an empty string 
        return "";
    }
};
