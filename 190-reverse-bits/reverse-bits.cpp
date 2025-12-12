class Solution {
public:
    int reverseBits(int n) {
        stack<int> bits;
        while (n > 0){
            bits.push(n%2);
            n /= 2;
        }
        int res = 0;
        long temp = 1;
        int count = bits.size();
        while (!bits.empty()){
            res += temp*bits.top();
            bits.pop();
            temp *= 2;
        }

        while (count < 32){
            res <<= 1;
            count++;
        }

        return res;
    }
};