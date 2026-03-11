class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int res = 0;
        int mul = 1;
        while (n > 0){
            // n%2==0 then 0
            res += (n%2 == 0)*mul;
            n /= 2;
            mul <<= 1;
        }

        return res;

    }
};