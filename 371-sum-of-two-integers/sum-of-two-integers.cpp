class Solution {
public:
    int getSum(int a, int b) {
        int sum = a^b;
        int carry = a&b;
        carry <<= 1;
        while (carry != 0){
            int temp = sum;
            sum = carry^sum;
            carry = temp&carry;
            carry <<= 1;
        }

        return sum;
    }
};