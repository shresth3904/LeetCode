class Solution {
public:
    int gen(vector<vector<int>>& grid, vector<vector<int>>&dp, int m, int n){
        if (m == 1 && n == 1) return grid[0][0];
        if (m == 0 || n == 0) return INT_MAX;

        if (dp[m][n] != -1) return dp[m][n];

        dp[m][n] = grid[m-1][n-1] + min(gen(grid, dp, m-1, n), gen(grid, dp, m, n-1));
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return gen(grid, dp, m, n);
    }
};