class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for(int i=0;i<strs[0].size();i++){
             // Iterate over all strings in the array
            for(auto s:strs){
                // if the current string is shorter than the current index 'i',
                // we return the result as the common prefix stops here
                if(i >= s.size() || s[i] != strs[0][i]){
                    return result;
                }
            }
            result += strs[0][i];
        }
        // If all strings have the same character at index 'i',
        // append that character from the first string to the result
        return result;
    }
};