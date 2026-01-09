class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NLE(n, n);
        stack<int> st;
        int mod = 1e9 +7;
        st.push(0);
        for (int i = 1; i < n; i++){
            while (!st.empty() && arr[st.top()] > arr[i]) {
                NLE[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> PLE(n, -1);
        stack<int> st2;
        st2.push(n-1);
        for (int i = n-2; i >= 0; i--){
            while (!st2.empty() && arr[st2.top()] >= arr[i]) {
                PLE[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++){
            long long left = i-PLE[i];
            long long right = NLE[i] - i;
            long long con = (left * right)%mod;
            long long adder = (arr[i] * con)%mod;
            res = (res+adder)%mod;
        }

        return (int)(res);
    }
};