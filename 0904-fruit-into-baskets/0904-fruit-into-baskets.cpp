class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, maxLen = 0;
        unordered_map<int, int> mpp;
        int k = 2;

        while (r < fruits.size()) {
            mpp[fruits[r]]++;
            
            // If we have more than k types of fruits, move the left pointer
            if (mpp.size() > k) {
                while (mpp.size() > k) {
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0) {
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }
            }

            // Update the maximum length of the subarray
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};