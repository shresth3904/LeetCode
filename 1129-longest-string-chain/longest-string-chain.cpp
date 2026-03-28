class Solution {
public:
    bool isvalid(string& a, string& b){
        int count = 0;
        int na = a.size();
        int nb = b.size();

        if (nb - na != 1) return false;
        for (int i = 0; i < na; i++){
            if (a[i] != b[i+count] && count < 1) {
                count++;
                i--;
            } else if (a[i] != b[i+count] && count == 1) return false;
        }

        return true;
        
    }


    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n, 1);

        int max_m = 1;
        for (int i = 1; i < n; i++){
            for (int j = i-1; j >= 0; j--){
                if (words[i].size() - words[j].size() > 1) break;
                if (isvalid(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            max_m = max(max_m, dp[i]);
        }

        return max_m;


    }
};