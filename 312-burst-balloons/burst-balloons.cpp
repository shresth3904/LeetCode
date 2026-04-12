class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        vector<int> arr(n+2, 1);
        for (int i = 1; i <= n; i++){
            arr[i] = nums[i-1];
        }
        

        for (int len = 2; len <= n+1; len++){
            for (int i = 0; i <= n-len +1; i++){
                int j = i + len;
                for (int k = i+1; k < j; k++){
                    int cost = arr[i] * arr[k]*arr[j];
                    int gain = cost + dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], gain);
                }
            }
        }

        return dp[0][n+1];
    }
};