class Solution {
public:
    void gen(vector<vector<int>>& res, vector<int>& curr, int start, int n, int k){
        if (curr.size() == k){
            res.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++){
            curr.push_back(i);
            gen(res, curr, i+1, n, k);
            curr.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;

        gen(res, curr, 1, n, k);

        return res;
    }
};