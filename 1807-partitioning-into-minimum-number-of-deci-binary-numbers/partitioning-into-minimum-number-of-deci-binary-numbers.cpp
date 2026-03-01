class Solution {
public:
    int minPartitions(string n) {
        set<int> nums;
        for (char c: n) nums.insert(c - '0');

        int prev_min = 0;
        int res = 0;
        for (auto&i : nums){
            res += (i - prev_min);
            prev_min = i;
        }

        return res;
    }
};