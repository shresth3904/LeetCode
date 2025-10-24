class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {

        if (nums.size() < 3) return -1;
        
        int min_num = INT_MAX;
        int max_num= INT_MIN;

        for (int i:nums){
            min_num = min(min_num, i);
            max_num = max(max_num, i);
        }

        if (min_num == max_num) return -1;

        for (int i:nums){
            if (i != min_num && i != max_num) return i;
        }

        return -1;
    }
};