class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        vector<int> dp2(n, 0);

        dp[0] = 1;
        for (int i = 1; i < n; i++) dp[i] = dp[i-1];

        for (int i = 1; i < m; i++){
            dp2[0] = dp[0]; 
            for (int j = 1; j < n; j++){
                dp2[j] = dp2[j-1]+ dp[j];
            }

            dp.swap(dp2);
        }

        return dp[n-1];
    }
};