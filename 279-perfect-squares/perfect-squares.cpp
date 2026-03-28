class Solution {
public:
    int numSquares(int n) {
        int lim = (int) pow(n, 0.5);
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        for (int i = 1; i <= lim; i++){
            for (int j = i*i; j <= n; j++){
                dp[j] = min(dp[j], dp[j - i*i] + 1);
            }
        }

        return dp[n];
    }
};