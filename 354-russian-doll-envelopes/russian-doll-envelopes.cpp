class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>&a, const vector<int>&b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = envelopes.size();
        vector<int> trail;
        for (int i = 0; i < n; i++){
            auto it = lower_bound(trail.begin(), trail.end(), envelopes[i][1]);
            if (it == trail.end()){
                trail.push_back(envelopes[i][1]);
            }

            else *it = envelopes[i][1];
        }

        return trail.size();
    }
};