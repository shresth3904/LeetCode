class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() < 3) return -1;

        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        int sum = a+b+c;

        int mn = min(min(a, b), c);
        int mx = max(max(a, b), c);

        return sum-mn-mx;
    }
};