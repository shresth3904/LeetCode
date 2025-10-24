class Solution {
public:


    void gen(vector<int>& cand, int target, vector<int>& curr, vector<vector<int>>& res, int start){
        for (int i = start; i < cand.size(); i++){
            if (cand[i] == target){
                curr.push_back(cand[i]);
                res.push_back(curr);
                curr.pop_back();
            }
            else if (cand[i] < target){
                curr.push_back(cand[i]);
                gen(cand, target-cand[i], curr, res, i);
                curr.pop_back();
            }
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        set<vector<int>> tracker;
        vector<int> c(10, 0);
        gen(candidates, target, curr, res, 0);

        return res;
    }
};