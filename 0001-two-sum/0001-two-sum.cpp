class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;  
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; 
            // Check if the complement is already in the map
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i}; 
            }
            // Otherwise, add the current number to the map
            num_map[nums[i]] = i;
        }
        return {};  
    }
};
