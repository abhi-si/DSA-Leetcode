class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxF = 0, maxLen = 0;
        vector<int> hash(26, 0); 

        while (r < s.size()) {
            hash[s[r] - 'A']++;
            maxF = max(maxF, hash[s[r] - 'A']);

// If the current window size minus the count of the most frequent character
// is greater than k, it means we need more than k replacements.
            if ((r - l + 1) - maxF > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            // Calculate the maximum length of the substring
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};