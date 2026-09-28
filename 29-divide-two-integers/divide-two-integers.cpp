class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        int sign = (dividend < 0) ^ (divisor < 0);

        long long ans = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Double divisor using bit shift
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        if (sign)
            ans = -ans;

        return (int)ans;
    }
};