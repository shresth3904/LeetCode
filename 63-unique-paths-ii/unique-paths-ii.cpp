class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        vector<int> dp2(n, 0);

        dp[0] = (grid[0][0] == 1)? 0: 1;
        for (int i = 1; i < n; i++) dp[i] = (grid[0][i] == 1)? 0: dp[i-1];

        for (int i = 1; i < m; i++){
            dp2[0] = (grid[i][0] == 1)? 0: dp[0]; 
            for (int j = 1; j < n; j++){
                dp2[j] = (grid[i][j] == 1)? 0:dp2[j-1] + dp[j];
            }

            dp.swap(dp2);
        }

        return dp[n-1];
    }
};