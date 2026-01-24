class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0; int right = nums.size()-1;
        int max_sum = 0;
        while (left < right){
            int sum = nums[left] + nums[right];
            max_sum = max(max_sum,sum);
            left++;
            right--;
        }

        return max_sum;
    }
};