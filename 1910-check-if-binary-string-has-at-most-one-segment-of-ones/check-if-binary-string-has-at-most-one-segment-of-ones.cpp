class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size()-1;
        while (s[n] != '1') n--;

        while (n--) if (s[n] == '0') return false;
        return true;
    }
};