class Solution {
public:
    void gen(vector<vector<int>>& res, vector<int>& curr, vector<bool>& check, vector<int>& nums){
        if (nums.size() == curr.size()){
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (check[i] || (i > 0 && nums[i] == nums[i - 1] && !check[i - 1]))
                continue;
            
            curr.push_back(nums[i]);
            check[i] = true;
            gen(res, curr, check, nums);
            check[i] = false;
            curr.pop_back();
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> check(nums.size(), false);
        gen(res, curr, check, nums);

        return res;
    }
};