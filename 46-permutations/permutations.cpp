class Solution {
public:
    void gen(vector<vector<int>>& res, vector<int>& curr, vector<bool>& pick, vector<int>& nums){
        if (nums.size() == curr.size()){
            res.push_back(curr);
            return;
        }
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (!pick[i]){
                pick[i] = true;
                curr.push_back(nums[i]);
                gen(res, curr, pick, nums);
                curr.pop_back();
                pick[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> pick(nums.size(), false);
        gen(res, curr, pick, nums);

        return res;
    }
};