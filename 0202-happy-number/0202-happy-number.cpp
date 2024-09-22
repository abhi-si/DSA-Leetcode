class Solution {
public:
    int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sumOfSquares(slow);       // Move slow pointer one step
            fast = sumOfSquares(sumOfSquares(fast));  // Move fast pointer two steps
        } while (slow != fast);
        
        // If the cycle ends at 1, then it's a happy number
        return slow == 1;
    }
};
