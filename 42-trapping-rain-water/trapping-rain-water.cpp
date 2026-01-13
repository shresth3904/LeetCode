class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> st;
        int res = 0;
        for (int i = 0; i <= n; i++){
            int bar = (i == n)? -1: height[i];
            while (!st.empty() && height[st.back()] < bar){
                int curr = st.back();
                st.pop_back();
                int PGE = (st.empty())? -1: st.back();
                if (PGE != -1 && bar != -1) {
                    res += (min(bar, height[PGE]) - height[curr]) * (i-PGE-1);
                }
            }

            st.push_back(i);
        }

        return res;
    }
};