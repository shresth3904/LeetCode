class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        int sum = 0;
        for (int i = 0; i < m; i++){
            sum += s1[i];
            dp[i+1][0] = sum;
        }
        sum = 0;
        for (int i = 0; i < n; i++){
            sum += s2[i];
            dp[0][i+1] = sum;
        }

        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (s1[row] == s2[col]) dp[row+1][col+1] = dp[row][col];
                else {
                    dp[row+1][col+1] = min(s1[row]+dp[row][col+1], s2[col]+ dp[row+1][col]);
                }
            }
        }

        return dp[m][n];
        
    }
};