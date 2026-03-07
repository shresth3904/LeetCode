class Solution {
public:
    
    vector<vector<int>> count(string s) {
        vector<vector<int>> counter(2, vector<int> (2, 0));
        int n = s.size();
        for (int i = 0; i < n; i++){
            counter[i%2 == 0][s[i]-'0']++;
        }
        return counter;
    }

    int minFlips(string s) {
        int n = s.size();
        vector<vector<int>> counter = count(s);
        if (n%2 == 0) return min(counter[0][1] + counter[1][0], counter[0][0] + counter[1][1]);
        int res = min(counter[0][1] + counter[1][0], counter[0][0] + counter[1][1]);

        s = s + s;

        for (int i = 0; i < n; i++){
            swap(counter[0], counter[1]);
            counter[1][s[i]-'0']++;
            counter[0][s[i]-'0']--;
            res = min(res, min(counter[0][1] + counter[1][0], counter[0][0] + counter[1][1]));
        }

        return res;
    }
};