class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c){
        int m = grid.size();
        int n = grid[0].size();
        stack<pair<int, int>> st;
        grid[r][c] = -1;
        st.push({r, c});
        vector<pair<int, int>> dir = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!st.empty()){
            auto ele = st.top();
            st.pop();

            for (auto d: dir){
                int sr = ele.first + d.first;
                int sc = ele.second + d.second;

                if (sr >= 0 && sc >= 0 && sr < m && sc < n && grid[sr][sc] == 1){
                    grid[sr][sc] = -1;
                    st.push({sr, sc});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < n; i++){
            if (grid[0][i] == 1){
                dfs(grid, 0, i);
            }
        }

        for (int i = 0; i < n; i++){
            if (grid[m-1][i] == 1){
                dfs(grid, m-1, i);
            }
        }

        for (int i = 0; i < m; i++){
            if (grid[i][0] == 1){
                dfs(grid, i, 0);
            }
        }

        for (int i = 0; i < m; i++){
            if (grid[i][n-1] == 1){
                dfs(grid, i, n-1);
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1) count++;
            }
        }


        return count;

    }
};