class Solution {
public:
    int gen(vector<vector<int>>& triangle,vector<vector<int>>& dp, int m, int n){
        if (m == triangle.size()-1) return triangle[m][n];
        if (dp[m][n] != INT_MIN) return dp[m][n];
        dp[m][n] = triangle[m][n] + min(gen(triangle, dp, m+1, n), gen(triangle, dp, m+1, n+1));
        return dp[m][n];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int> (m, INT_MIN));
        return gen(triangle, dp, 0, 0);
    }
};