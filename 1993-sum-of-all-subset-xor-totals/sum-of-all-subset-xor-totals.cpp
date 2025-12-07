class Solution {
public:
    void gen(vector<int>& nums, vector<int>& subset, int& result, int index){
        if (index == nums.size()){
            int sum = 0;
            for (int i: subset){
                sum = sum^i;
            }

            result += sum;
            return;
        }

        gen(nums, subset, result, index+1);
        subset.push_back(nums[index]);
        gen(nums, subset, result, index+1);
        subset.pop_back();
    }


    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        vector<int> subset;
        gen(nums, subset, sum, 0);

        return sum;
    }
};