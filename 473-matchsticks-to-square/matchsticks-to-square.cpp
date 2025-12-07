class Solution {
public:
    bool gen(vector<int>& matchsticks, int& target, int index, vector<int>& subset){
        if (index == matchsticks.size()){
            return (subset[0] == target && subset[1] == target
                    && subset[2] == target && subset[3] == target);
        }
        int addend = matchsticks[index];
        for (int i = 0; i < 4; i++){
            if (i > 0 && subset[i] == subset[i-1]) continue;
            if (subset[i]+addend <= target){
                subset[i] += addend;
                if (gen(matchsticks, target, index+1, subset) == true) return true;
                subset[i] -= addend;
            }
        }

        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int i: matchsticks) sum+=i;

        if (sum%4 != 0) return false;

        int target = sum/4;
        vector<int> subset(4, 0);
        return gen(matchsticks, target, 0, subset);
    }
};