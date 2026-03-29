class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> dp(n+1, 0);
        vector<int> dp2(n+1, 0);

        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if ((text1[i-1] == text2[j-1])){
                    dp2[j] = 1 + dp[j-1];
                }

                else dp2[j] = max(dp[j], dp2[j-1]);
            }
            dp.swap(dp2);
        }

        return dp[n];
    }
};