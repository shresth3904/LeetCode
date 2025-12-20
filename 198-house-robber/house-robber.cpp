class Solution {
public:
    int gen(int n, vector<int>& nums, vector<int>& dp){
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        dp[n] = nums[n] + max(gen(n-2, nums, dp), gen(n-3, nums, dp));
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return max(gen(n-1, nums, dp), gen(n-2, nums, dp));
    }
};