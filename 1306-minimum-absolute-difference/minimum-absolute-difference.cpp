class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        vector<vector<int>> res;
        for (int i = 0; i < arr.size()-1; i++){
            int abs_diff = arr[i+1] - arr[i];
            if (abs_diff < min_diff){
                min_diff = abs_diff;
                res.clear();
                res.push_back({arr[i], arr[i+1]});
            }
            else if (abs_diff == min_diff) res.push_back({arr[i], arr[i+1]});
        }

        return res;
    }
};