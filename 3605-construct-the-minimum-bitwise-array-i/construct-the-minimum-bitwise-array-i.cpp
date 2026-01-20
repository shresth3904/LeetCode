class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        for (int k = 0; k < n; k++){
            for (int i = 0; i < nums[k]; i++){
                if ((i | i+1) == nums[k]) {
                    res[k] = i;
                    break;
                }
            }
        }

        return res;
    }
};