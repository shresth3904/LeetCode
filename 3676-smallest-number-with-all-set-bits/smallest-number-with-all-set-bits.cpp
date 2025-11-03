class Solution {
public:
    int smallestNumber(int n) {
        int count = 0;
        int num = 1;
        while (n >= num) {
            count++;
            num *= 2;
        }

        int res = pow(2, count) - 1;
        return res;
    }
};