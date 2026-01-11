class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;
        for (int i = 0; i <= n; i++){
            int h = (i == n)? 0: heights[i];
            
            while (!st.empty() && h < heights[st.top()]){
                int temp = heights[st.top()];
                st.pop();

                int width = (st.empty())? i: i - st.top() -1;
                max_area = max(max_area, temp*width); 
            }

            st.push(i);
        }

        return max_area;
    }

    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max_area = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int sub_res = largestRectangleArea(heights);
            max_area = max(max_area, sub_res);
        }

        return max_area;
    }
};