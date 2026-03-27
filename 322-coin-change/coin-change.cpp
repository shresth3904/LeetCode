class Solution {
public:
    int gen(vector<int>& coins, int amt, vector<int>& dp){
        if (amt == 0) return 0;
        else if (amt < 0) return -1;

        if (dp[amt] != -2) return dp[amt];

        int n = coins.size();
        int res = INT_MAX;
        while (n--){
            int count = gen(coins, amt - coins[n], dp);
            if (count != -1) res = min(res, count +1); 
        }
        dp[amt] = (res == INT_MAX)? -1: res;
        return dp[amt];

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -2);
    
        return gen(coins, amount, dp);
    }
};