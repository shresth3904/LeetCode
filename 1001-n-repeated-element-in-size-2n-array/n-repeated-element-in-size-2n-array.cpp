class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int res = nums[0];
        unordered_map<int, int> hash;

        for (int i: nums){
            hash[i]++;
            if (hash[res] < hash[i]) res = i;
            if (hash[i] >= 2) return i;
        }

        return res;
    }
};