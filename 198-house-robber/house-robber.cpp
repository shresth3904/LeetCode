class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;

        for (int i = 0; i < nums.size(); i++){
            int temp = a;
            a = max(a, b+nums[i]);
            b = temp;
        }

        return a;
    }
};