class Solution {
public:
    int gen(int m, int n, vector<vector<int>>& dp){
        if (m == 1 && n == 1) return 1;
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        dp[m][n] = gen(m-1, n, dp) + gen(m, n-1, dp);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return gen(m, n, dp);
    }
};