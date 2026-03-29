class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 1e9));
        dp[1][1] = grid[0][0];

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                dp[i+1][j+1] = min(dp[i+1][j+1], grid[i][j] + min(dp[i][j+1], dp[i+1][j]));
            }
        }

        return dp[m][n];
    }
};