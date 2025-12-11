class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool neg = (dividend > 0)^(divisor > 0);
        long long dor = abs((long long)divisor);long long dend = abs((long long)dividend);
        long long sub = dor;
        long long temp = 1;
        long long res = 0;
        while (dend >= dor){
            sub <<= 1;
            temp <<= 1;
            if (sub > dend){
                sub >>= 1;
                temp >>= 1;
                dend -= sub;
                sub = dor;
                res += temp;
                temp = 1;
            }
        }

        return (neg)? -res: res;
    }
};