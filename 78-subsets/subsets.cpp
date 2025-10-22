class Solution {
public:
void generator(vector<vector<int>>& res,vector<int>& nums, vector<int>& arr, int current, int n){
            if(current == n){
                res.push_back(arr);
                return;
            }

            generator(res, nums, arr, current+1, n);
            arr.push_back(nums[current]);
            generator(res, nums, arr, current+1, n);
            arr.pop_back();
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr = {};
        generator(res, nums, arr, 0, nums.size());
        return res;
    }
};