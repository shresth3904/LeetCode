class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        deque<int> q;
        q.push_back(0);
        int ans = dp[0];
        for (int i = 1; i< n; i++){
            dp[i] = max(nums[i] + dp[q.front()], nums[i]);

            while (!q.empty() && dp[q.back()] < dp[i]){
                q.pop_back();
            }

            q.push_back(i);

            while (!q.empty() && i - q.front() >= k){
                q.pop_front();
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};