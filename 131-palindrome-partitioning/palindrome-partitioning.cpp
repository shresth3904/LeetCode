class Solution {
public:
    bool pall(string s){
        for (int i = 0, n = s.size(); i < n/2; i++){
            if (s[i] != s[n-i-1]) return false;
        }
        return true;
    }

    void gen(vector<string>& curr, vector<vector<string>>& res, int start, string & s){
        if (start == s.size()){
            res.push_back(curr);
            return;
        }

        for(int i = 1;i <= s.size()-start; i++){
            string focus = s.substr(start, i);
            if (pall(focus)){
                curr.push_back(focus);
                gen(curr, res, start+i, s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        gen(curr, res, 0, s);

        return res;
    }
};