class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int i = INT_MAX, ii = INT_MAX, iii = INT_MAX;

        for (int k = 1; k < nums.size(); k++){
            int num = nums[k];
            if (num < i){
                ii = i;
                i = num;
            }
            else if (num < ii){
                ii = num;
            }
        }

        return i + ii + nums[0];
    }
};