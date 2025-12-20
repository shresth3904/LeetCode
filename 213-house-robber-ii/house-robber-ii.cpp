class Solution {
public:
    int house(vector<int>& nums, int start, int end){
        if (start-end == 0) return nums[start];
        int a = 0, b = 0;
        for (int i = start; i < end; i++){
            int temp = a;
            a = max(a, b+nums[i]);
            b = temp;
        }  

        return a;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(house(nums, 0, n-1), house(nums, 1, n));
    }
};