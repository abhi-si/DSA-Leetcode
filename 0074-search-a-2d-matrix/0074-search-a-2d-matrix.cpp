class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false; 
        
        int n = matrix.size();        
        int m = matrix[0].size();     
        int r = 0;                   
        int c = m - 1;                // Start from the last column

        while (r < n && c >= 0) {
            if (matrix[r][c] == target) 
                return true;           // Target found
            else if (matrix[r][c] > target) 
                c--;  // Move left if current element is greater than target
            else 
                r++; // Move down if current element is less than target
        }
        return false; 
    }
};
