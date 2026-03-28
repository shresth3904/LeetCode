class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_left(n, 1);
        vector<int> dp_right(n, 1);

        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]) dp_left[i] = max(dp_left[i], 1 + dp_left[j]);
            }
        }

        for (int i = n-2; i >= 0; i--){
            for (int j = n-1; j > i; j--){
                if (nums[i] > nums[j]) dp_right[i] = max(dp_right[i], dp_right[j] + 1);
            }
        }

        int max_m = 1;
        for (int i = 0; i < n; i++){
            if (dp_left[i] > 1 && dp_right[i] > 1) max_m = max(max_m, dp_left[i] + dp_right[i]);
        }

        return n- max_m +1;
    }
};