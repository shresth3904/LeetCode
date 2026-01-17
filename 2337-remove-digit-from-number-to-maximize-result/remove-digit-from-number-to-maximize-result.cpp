class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        string max_str = "";
        while (n--){
            if (number[n] == digit){
                string sub = number.substr(0, n) + number.substr(n+1);
                max_str = max(max_str, sub);
            }
        }

        return max_str;
    }
};