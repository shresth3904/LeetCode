class Solution {
public:
    int next(vector<int>& nums, int j){
        int base = nums[j];
        for (int i = j+1; i < nums.size(); i++){
            if (nums[i] > base) return nums[i];
        }

        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums2.size(); i++){
            hash[nums2[i]] = i;
        }

        for (int i = 0; i < nums1.size(); i++){
            if (hash.find(nums1[i]) != hash.end()) nums1[i] = next(nums2, hash[nums1[i]]);
            else nums1[i] = -1;
        }

        return nums1;
    }
};