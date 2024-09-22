class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;  // Stores the last index of each element
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (mpp.find(nums[i]) != mpp.end() && i - mpp[nums[i]] <= k) {
                return true;  // Found a duplicate within the required range
            }
            mpp[nums[i]] = i;  // Update the index of the current element
        }
        return false;
    }
};
