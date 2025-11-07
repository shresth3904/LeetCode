class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> storage;
        for (int i:nums){
            if (storage.count(i) != 0) return true;
            storage.insert(i);
        }

        return false;
    }
};