class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int carry = 0;
        int steps = 0;

        for (int i = n-1; i > 0; i--){
            int curr = (s[i]-'0') + carry;
            if (curr == 1){
                steps += 2;
                carry = 1;
            }

            else {
                steps += 1;
            }
        }

        return steps + carry;
    }
};