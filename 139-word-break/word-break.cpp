class Solution {
public:
    bool gen(string s, vector<string>& wordDict, int start, vector<int>& tracker){
        if (start == s.size()) return true;
        if (tracker[start] != -1) return tracker[start];
        for (string i: wordDict){
            int n = i.size();
            if (n+start <= s.size() && s.substr(start, n) == i && gen(s, wordDict, start+n, tracker)){
                return tracker[start] = true;
            }
        }

        return tracker[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> tracker(s.size(), -1);
        return gen(s, wordDict, 0, tracker);
    }
};