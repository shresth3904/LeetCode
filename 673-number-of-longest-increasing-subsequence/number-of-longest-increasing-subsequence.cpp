class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> dp(n, {1, 1});

        int max_sq = 1;
        int max_count = 1;
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]) {
                    if (dp[i].first < dp[j].first + 1){
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    } else if (dp[i].first == dp[j].first + 1) dp[i].second += dp[j].second;
                }
            }
            if (dp[i].first > max_sq){
                max_sq = dp[i].first;
                max_count = dp[i].second;
            } else if (dp[i].first == max_sq) max_count += dp[i].second;
        }

        return max_count;
    }
};