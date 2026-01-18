class Solution {
public:
    int vowelConsonantScore(string s) {
        int c = 0;
        int v = 0;

        for (char i: s){
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') v++;
            else if (i >= 'a' && i <= 'z')c++;
        }

        return (c>0)? v/c: 0;
    }
};