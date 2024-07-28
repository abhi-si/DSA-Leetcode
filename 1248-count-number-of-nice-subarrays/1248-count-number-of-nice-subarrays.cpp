class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, oddCount = 0, result = 0;

        while (r < nums.size()) {
            if (nums[r] % 2 == 1) {
                oddCount++;
            }

            while (oddCount > k) {
                if (nums[l] % 2 == 1) {
                    oddCount--;
                }
                l++;
            }

            if (oddCount == k) {
                int tempL = l;
                while (tempL <= r && nums[tempL] % 2 == 0) {
                    tempL++;
                }
                result += tempL - l + 1;
            }
            
            r++;
        }

        return result;
    }
};
