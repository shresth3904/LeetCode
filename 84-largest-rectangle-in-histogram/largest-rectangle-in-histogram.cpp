class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NLE(n, n);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++){
           while (!st.empty() && heights[st.top()] > heights[i]){
                NLE[st.top()] = i;
                st.pop();
           }
           st.push(i);
        }

        vector<int> PLE(n, -1);
        stack<int> st2;
        st2.push(n-1);
        for (int i = n-2; i >= 0; i--){
           while (!st2.empty() && heights[st2.top()] > heights[i]){
                PLE[st2.top()] = i;
                st2.pop();
           }
           st2.push(i);
        }


        int max_area = 0;

        for (int i = 0; i < n; i++){
            max_area = max(max_area, heights[i]*(NLE[i]-PLE[i]-1));
        }

        
        return max_area;

    }
};