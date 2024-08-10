class Solution {
public:
    void func(int ind, string s, vector<string>& currStr, vector<vector<string>>& ans) {
        if(ind == s.size()) {
            ans.push_back(currStr);
            return;
        }
        for(int i = ind; i < s.size(); i++) {
            if(isPalindrome(s, ind, i)) {
                currStr.push_back(s.substr(ind, i - ind + 1));
                func(i + 1, s, currStr, ans);
                currStr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currStr;
        func(0, s, currStr, ans);
        return ans;
    }
};
