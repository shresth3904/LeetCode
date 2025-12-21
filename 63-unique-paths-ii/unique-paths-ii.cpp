class Solution {
public:
    int gen(vector<vector<int>>& grid,int m, int n, vector<vector<int>>& dp){
        if (m == 0 || n == 0) return 0;
        if (grid[m-1][n-1] == 1) return 0;
        if (m == 1 && n == 1) return 1;

        if (dp[m][n] != -1) return dp[m][n];
        dp[m][n] = gen(grid, m-1, n, dp) + gen(grid, m, n-1, dp);
        return dp[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return gen(obstacleGrid, m, n, dp);
    }
};