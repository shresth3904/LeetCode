class Solution {
public:
    void gen(string digits, string curr, int i, vector<string>& res, vector<vector<char>>& comb){
        if (digits.size() == curr.size()){
            res.push_back(curr);
            return;
        }
        for (char c: comb[digits[i] - '2']){
            gen(digits, curr + c, i+1, res, comb);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> comb = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };

        vector<string> res;
        gen(digits, "", 0, res, comb);

        return res;
        
    }
};