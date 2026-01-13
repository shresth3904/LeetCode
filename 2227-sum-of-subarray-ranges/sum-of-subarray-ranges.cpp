class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        
        vector<pair<int, int>> LE(n, {n, -1});

        for (int i = 0; i < n; i++){
            while (!st.empty() && nums[st.top()] >= nums[i]){
                LE[st.top()].first = i;
                st.pop();
            }

            LE[i].second = (st.empty())? -1: st.top();
            st.push(i);
        }

        vector<pair<int, int>> GE(n, {n, -1});
        stack<int> st2;
        for (int i = 0; i < n; i++){
            while (!st2.empty() && nums[st2.top()] <= nums[i]){
                GE[st2.top()].first = i;
                st2.pop();
            }

            GE[i].second = (st2.empty())? -1: st2.top();
            st2.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++){
            res += (long long)(GE[i].first-i)*(i - GE[i].second)*nums[i];
            res -= (long long)(LE[i].first-i)*(i - LE[i].second)*nums[i];
        }

        return res;
    }
};