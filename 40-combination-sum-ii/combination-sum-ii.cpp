class Solution {
public:

    void gen(vector<int>& cand, int target, vector<int>& curr, vector<vector<int>>& res, int start){

        if (target == 0){
                res.push_back(curr);
                return;
            }
        for (int i = start; i < cand.size(); i++){
            if (cand[i] > target) break;

            else if (cand[i] <= target){
                if (i > start && cand[i] == cand[i-1]) continue;
                curr.push_back(cand[i]);
                gen(cand, target-cand[i], curr, res, i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        gen(candidates, target, curr, res, 0);
        return res;
    }
};