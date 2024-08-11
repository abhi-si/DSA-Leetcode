class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intsec;
        int i = 0, j = 0;
        
        // Ensure both arrays are sorted, as this algorithm assumes sorted arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // Avoid duplicates in the intersection result
                if (intsec.empty() || intsec.back() != nums1[i]) {
                    intsec.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return intsec;
    }
};
