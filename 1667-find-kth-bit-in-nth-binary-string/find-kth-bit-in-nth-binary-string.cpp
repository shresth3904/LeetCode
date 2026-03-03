class Solution {
public:
    char gen(int n, int k, bool invert){
        if (n == 1) {
            return (invert)? '1': '0';
        }

        else if (k == n/2) return (invert)? '0': '1';
        else if (k < n/2) return gen(n/2, k, invert);
        else return gen(n/2, n-k-1, !invert);
    }

    char findKthBit(int n, int k) {
        int len = (1 << n+1) - 1;
        return gen(len, k-1, false);
    }
};