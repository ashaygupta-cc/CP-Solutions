class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
      
        long reverse = 0;
        long num = x;
        while (num > 0) {
            int digit = num % 10;
            reverse = digit + reverse * 10;
            num /= 10;
        }
        return x == reverse;
    }
};