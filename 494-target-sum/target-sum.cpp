class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0; for (int & i: nums) total_sum += i;
        if ((total_sum+target) %2 != 0 || abs(target) > total_sum) return 0;

        int target_sum = (total_sum+target)/2;
        int n = nums.size();

        vector<int> dp(target_sum + 1, 0);
        dp[0] = 1;
        
        for (int num: nums){
            for (int j = target_sum; j >= num; j--){
                dp[j] += dp[j - num];
            }
        }

        return dp[target_sum];
    }
};