class Solution {
public:
    void gen(vector<int>& nums,vector<int>& current, int start, vector<vector<int>>& res){
        res.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            current.push_back(nums[i]);
            gen(nums, current, i + 1, res);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        vector<vector<int>> res;

        gen(nums, current, 0, res);
        return res;
    }
};