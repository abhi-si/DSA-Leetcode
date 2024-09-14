class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m1; // Maps pattern characters to words
        unordered_map<string, char> m2; // Maps words to pattern characters
//istringstream: It's a stream class that operates on a string buffer. It allows you to read formatted data (like words) from the string.
//iss(s): Initializes the input string stream with the content of the string s, so that it can be processed word by word.
        istringstream iss(s);
        string word;
        int i = 0;
        int n = pattern.size();

// The while (iss >> word) condition is both extracting each word from the stream and checking if the stream is still valid after each extraction. The loop continues as long as there are words to be extracted from the string.
        while (iss >> word) {
            if (i == n) return false; // If there are more words than pattern characters
            char p = pattern[i];

            // If p has already been mapped, check if it maps to the correct word
            if (m1.count(p)) {
                if (m1[p] != word) return false;
            }
            // If the word has already been mapped, check if it maps to the correct character
            else if (m2.count(word)) {
                if (m2[word] != p) return false;
            }
            // Map the character to the word and the word to the character
            else {
                m1[p] = word;
                m2[word] = p;
            }
            i++;
        }

        return i == n; // Ensure there are no leftover pattern characters
    }
};
