class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
 // If there are 2 or fewer elements, all are valid.

        int i = 1; // Start from the second element
        for (int j = 2; j < nums.size(); j++) {
            if (nums[j] != nums[i - 1]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1; // Length of array with each element appearing at most twice
    }
};
