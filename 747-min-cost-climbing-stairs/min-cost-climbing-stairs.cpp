class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[1], b = cost[0];
        for (int i = 2; i < cost.size(); i++){
            int temp = cost[i] + min(a, b);
            b = a;
            a = temp;
        }

        return min(a, b);
    }
};