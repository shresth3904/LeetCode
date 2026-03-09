

class Solution {
public:
    int memo[201][201][2];
    int MOD = 1e9 + 7;

    int gen(int zero, int one, int last, int limit){
        
        if (zero == 0 && one == 0){
            return 1;
        }
        
        if (last != 2 && memo[zero][one][last] != -1){
            return memo[zero][one][last];
        }

        long long ways = 0;

        if (last != 0){
            for (int k = 1; k <= min(zero, limit); k++){
                ways = (ways + gen(zero - k, one, 0, limit))%MOD;
            }
        }

        if (last != 1){
            for (int k = 1; k <= min(one, limit); k++){
                ways = (ways + gen(zero, one - k, 1, limit))%MOD;
            }
        }

        if (last != 2){
            memo[zero][one][last] = ways;
        }

        return ways;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(memo, -1, sizeof(memo));
        return gen(zero , one, 2, limit);
    }
};