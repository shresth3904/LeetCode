class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        int n = nums.size();

        for (int &i: nums){
            int sum = 0;
            while (i > 0){
                sum += i%10;
                i /= 10;
            }
            res = min(res, sum);
        }

        return res;
    }
};