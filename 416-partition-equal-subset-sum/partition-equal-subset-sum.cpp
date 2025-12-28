class Solution {
public:
    bool gen(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
        if (target == 0) return true;
        if (index == 0){
            return nums[index] == target;
        } 
        if (dp[index][target] != -1) return dp[index][target];
        bool exc = gen(nums, index-1, target, dp);
        bool inc = false;
        if (target - nums[index] >= 0) inc = gen(nums, index-1, target - nums[index], dp);

        return dp[index][target] = exc || inc;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i: nums) sum += i;
        if (sum%2 != 0) return false;

        vector<vector<int>> dp(n+1, vector<int> (sum/2+1, -1));
        return gen(nums, n-1, sum/2, dp);
    }
};