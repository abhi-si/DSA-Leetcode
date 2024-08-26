class Solution {
public:
    int climbStairs(int n) {
        // Declare an array of size n+1 to store the number of ways to reach each step
        int dp[n+1];
        dp[0] = 1; // There's 1 way to stay at the ground
        dp[1] = 1; // There's 1 way to reach the first step
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];  
        }
        
        return dp[n]; 
    }
};
