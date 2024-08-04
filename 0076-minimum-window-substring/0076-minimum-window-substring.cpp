class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n == 0 || m == 0) return "";

        vector<int> hash(256, 0);
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        int cnt = 0, l = 0, r = 0, minLen = INT_MAX, sInd = -1;
        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            r++;

            while (cnt == m) {
                if (r - l < minLen) {
                    minLen = r - l;
                    sInd = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
        }
        return (sInd == -1) ? "" : s.substr(sInd, minLen);
    }
};
