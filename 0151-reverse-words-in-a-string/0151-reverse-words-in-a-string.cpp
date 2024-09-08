class Solution {
public:
    string reverseWords(string s) {
        string temp = ""; // Temporary string to hold each word as we traverse the input
        stack<string> st; // Stack to store words in reverse order

        // Traverse each character in the input string 's'
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i]; // Current character

            // If we encounter a space, it indicates the end of a word
            if (s[i] == ' ') {
                if (temp != "") { // If 'temp' contains a word (i.e., it's not empty)
                    st.push(temp); // Push the word into the stack
                }
                temp = ""; // Reset 'temp' to collect the next word
            } 
            else {
                // If it's not a space, we are still building a word
                temp += ch; // Append the current character to 'temp'
            }
        }

        // After the loop, if 'temp' has a word that hasn't been added to the stack yet
        if (temp != "") {
            st.push(temp); // Push the last word into the stack
        }

        string ans = "";

        // Pop all words from the stack to reverse their order
        while (!st.empty()) {
            ans += (st.top() + " "); // Add the top word from the stack to 'ans' with a space
            st.pop(); // Remove the top word from the stack
        }

        if (!ans.empty()) {
            ans.pop_back(); // Remove the extra space added after the last word
        }

        return ans; 
    }
};
