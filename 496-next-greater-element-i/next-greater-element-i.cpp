class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        stack<int> st;
        int n = nums2.size()+1;
        while (--n){
            if (!st.empty()){
                while (!st.empty() && st.top() < nums2[n-1]) st.pop();
                hash[nums2[n-1]] = (!st.empty())? st.top():-1;
            }
            else hash[nums2[n-1]] = -1;

            st.push(nums2[n-1]);
        }

        for (int i = 0; i < nums1.size(); i++) nums1[i] = hash[nums1[i]];
        return nums1;
    }
};