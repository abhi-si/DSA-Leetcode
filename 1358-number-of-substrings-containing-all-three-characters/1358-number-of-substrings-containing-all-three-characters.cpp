class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int lastSeen[3] = {-1, -1, -1}, cnt = 0;
        for (int i = 0; i < n; ++i) {
 // s[i] - 'a' calculates the difference between the ASCII value of the 
 // character at s[i] and the ASCII value of 'a'.
            lastSeen[s[i] - 'a'] = i;
// By setting lastSeen[s[i] - 'a'] = i, the code updates the corresponding
// position in lastSeen array to the current index i.
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                cnt += (min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1);
            }
        }
        return cnt;
    }
};
