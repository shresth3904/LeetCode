class Solution {
public:
    int gen(vector<int>& nums, int target, int index){
        if (index == nums.size()){
            if (target == 0) return 1;
            return 0;
        }

        int count = gen(nums, target + nums[index], index + 1) + gen(nums, target - nums[index], index+1);
        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return gen(nums, target, 0);
    }
};