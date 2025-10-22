class Solution {
public:

    void generator(vector<string>& res, string current, int open, int close, int n){
        if (open + close == 2*n){
            res.push_back(current);
            return;
        }

        if (open < n){
            generator(res, current + '(', open+1, close, n);
        }

        if (close < open){
            generator(res, current+')', open, close+1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generator(res, "", 0, 0, n);
        return res;
    }
};