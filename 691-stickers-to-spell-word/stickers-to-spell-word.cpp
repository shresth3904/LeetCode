class Solution {
public:
    string apply(const string& target,vector<int>& table){
        string res = "";
        vector<int> temp = table;

        for (char c: target){
            if (temp[c-'a'] > 0) temp[c-'a']--;
            else res += c;
        }
        sort(res.begin(), res.end());
        return res;
    }
    int gen(const string& target, vector<vector<int>>& table, unordered_map<string, int>& dp){
        if (target == "") return 0;
        if (dp.find(target) != dp.end()) return dp[target];
        char focus = target[0];
        int res = INT_MAX;
        for (auto& i: table){
            if (i[focus-'a'] > 0){
                string new_target = apply(target, i);
                int sub_res = gen(new_target, table, dp);
                if (sub_res != -1) res = min(res, 1 + sub_res);
            }
        }

        dp[target] = (res == INT_MAX)? -1: res;
        return dp[target];

    }
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> table;
        for (string s: stickers){
            vector< int> hash(26, 0);
            for (char c: s) hash[c-'a']++;
            table.push_back(hash);
        }
        sort(target.begin(), target.end());
        unordered_map<string, int> dp;
        return gen(target, table, dp);
    }
};