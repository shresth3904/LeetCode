class Solution {
public:
    int gen(vector<int>& nums, int target, int index, vector<vector<int>>& dp, int& total_sum){
        if (index == nums.size()){
            if (target == 0) return 1;
            return 0;
        }
        if (abs(target) > total_sum) return 0;
        int offset_target = target + total_sum;
        if (dp[index][offset_target] != -1) return dp[index][offset_target];

        dp[index][offset_target] = gen(nums, target + nums[index], index + 1, dp, total_sum) + gen(nums, target - nums[index], index+1, dp, total_sum);
        return dp[index][offset_target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0; for (int i: nums) total_sum += i;
        if (abs(target) > total_sum) return 0;
        vector<vector<int>> dp(nums.size()+1, vector<int> (2* total_sum + 1, -1));
        return gen(nums, target, 0, dp, total_sum);
    }
};