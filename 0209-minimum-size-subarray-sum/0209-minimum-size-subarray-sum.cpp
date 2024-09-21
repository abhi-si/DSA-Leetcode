class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0; 
        int r = 0;
        int sum = 0; 
        int minLength = INT_MAX;
        
        while (r < nums.size()) {
             sum += nums[r];
            
            // Shrink the window from the left as long as the sum is greater or equal to target
            while (sum >= target) {
                // Update the minimum length of the subarray
                minLength = min(minLength, r - l + 1);
                
                // Shrink the window by subtracting the left value and moving the left pointer
                sum -= nums[l];
                l++;
            }
            r++;
        }
        
        // If minLength is not updated, return 0, else return the minLength
        return minLength == INT_MAX ? 0 : minLength;
    }
};
