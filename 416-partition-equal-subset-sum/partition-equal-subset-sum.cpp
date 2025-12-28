class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0; for(int i: nums) sum += i;
        if (sum %2 != 0) return false;
        vector<vector<bool>> dp(n+1, vector<bool> (sum/2 + 1, 0));
        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= sum/2) dp[0][nums[0]] = true;

        for (int index = 1; index < n; index++){
            for (int target = 0; target <= sum/2; target++){
                bool exc = dp[index-1][target];
                bool inc = false;
                if (target - nums[index] >= 0) inc = dp[index-1][target-nums[index]];

                dp[index][target] = inc || exc;
            }
        }

        return dp[n-1][sum/2];
        
    }
};