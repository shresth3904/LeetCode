class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n);
        int i = 2*n;
        while (i--){
            if (st.empty()){
                res[(i)%n] = -1; 
            }
            else {
                while (!st.empty() && st.top() <= nums[(i)%n]) st.pop();
                res[(i)%n] = (st.empty())? -1: st.top(); 
            }

            st.push(nums[(i)%n]);
        }

        return res;
    }
};