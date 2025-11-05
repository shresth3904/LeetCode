class Solution {
public:
    void gen(vector<vector<int>>& res, vector<int>& curr, int k, int n, int start, int sum){
        if (curr.size() == k){
            if (sum == n) res.push_back(curr);
            return;
        }

        for (int i = start; i < 10; i++){
            if (i <= n-sum) {
                curr.push_back(i);
                gen(res, curr, k, n, i+1, sum+i);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        gen(res, curr, k, n, 1, 0);

        return res;
    }
};