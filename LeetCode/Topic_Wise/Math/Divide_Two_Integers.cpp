class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; 
        }

        bool negative = (dividend < 0) ^ (divisor < 0);
        
        long long absdivi = abs((long long)dividend);
        long long absdivs = abs((long long)divisor);
        long long quotient = 0;

        while (absdivi >= absdivs) {
            long long calcdiv = absdivs, multiple = 1;
            while (absdivi >= (calcdiv << 1)) {
                calcdiv <<= 1;
                multiple <<= 1;
            }
            absdivi -= calcdiv;
            quotient += multiple;
        }

        quotient = negative ? -quotient : quotient;

        if (quotient > INT_MAX) {
            return INT_MAX;
        }
        if (quotient < INT_MIN) {
            return INT_MIN;
        }

        return quotient;
    }
};
