class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        
        // Traverse through all the strings
        for (string s : strs) {
            //want to maintain original strs
            string key = s; 
            // Sort the string to generate the key for anagram groups
            sort(key.begin(), key.end());
            
            // Group anagrams together in the map
            anagramMap[key].push_back(s);
/**{
    "aet": ["eat", "tea", "ate"],
    "ant": ["tan", "nat"],
    "abt": ["bat"]
}
**/
        }
        
        // Prepare the result by extracting the groups from the map
        vector<vector<string>> result;
        for (auto it : anagramMap) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
