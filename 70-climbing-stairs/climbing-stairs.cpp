class Solution {
public:
    int gen(int n, vector<int>& dp){
        if (dp[n] != -1) return dp[n];
        if (n <= 1) return 1;
        dp[n] = gen(n-1, dp) + gen(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return gen(n, dp);
    }
};