class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (nums.size() > 1){
            int minSum = INT_MAX;
            int t = -1;
            bool sorted = true;
            for (int i = 0; i < nums.size()-1; i++){
                int sum = nums[i] + nums[i+1];
                if (sum < minSum) {
                    minSum = sum;
                    t = i;
                }

                if (nums[i] > nums[i+1]) sorted = false;

            }

            if (sorted) break;

            nums[t] = minSum;
            nums.erase(nums.begin() + t + 1);
            count++;
        }


        return count;
    }
};