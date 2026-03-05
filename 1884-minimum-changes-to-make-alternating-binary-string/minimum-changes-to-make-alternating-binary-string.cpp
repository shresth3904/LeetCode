class Solution {
public:
    int minOperations(string s) {
        int counter[2][2] = {{0, 0}, {0, 0}};
        

        int flip = true;
        for (char c: s){
            counter[flip][c-'0']++;
            flip = !flip;
        }

        return min(counter[0][1] + counter[1][0], counter[0][0] + counter[1][1]);
    }
};