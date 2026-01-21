class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& i: nums){
            int res = -1;
            int d = 1;
            while ((i & d) != 0){
                res = i - d;
                d <<= 1;
            } 

            i = res;
        }

        return nums;
    }
};