class Solution {
public:
    void gen(string digits, string& curr, int i, vector<string>& res, vector<vector<char>>& comb){
        if (digits.size() == curr.size()){
            res.push_back(curr);
            return;
        }
        for (char c: comb[digits[i] - '2']){
            curr.push_back(c);
            gen(digits, curr, i+1, res, comb);
            curr.pop_back();
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
        string curr = "";
        gen(digits, curr, 0, res, comb);

        return res;
        
    }
};