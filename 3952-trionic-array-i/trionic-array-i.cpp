class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int peak = 0;
        int valley = 0;
        for (int i = 1; i < nums.size()-1; i++){
            if (nums[i-1] == nums[i] || nums[i] == nums[i+1]) return false;
            if (nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                if (peak > 0) return false;
                peak++;
            }

            else if (nums[i-1] > nums[i] && nums[i] < nums[i+1]){
                if (peak != 1 || valley > 0) return false;
                valley++;
            }
        }

        return (peak == 1 && valley == 1)? true: false;
    }
};