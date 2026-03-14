class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i<m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) count++;
            }
        }

        if (count == 0) return 0;

        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int min = 0;

        while (!q.empty() && count > 0){
            int curr_lvl = q.size();
            for (int i = 0; i < curr_lvl; i++){
                auto [r, c] = q.front();
                q.pop();

                for (auto d: dir){
                    int rc = r + d.first;
                    int cc = c + d.second;

                    if (rc >= 0 && rc < m && cc >= 0 && cc < n && grid[rc][cc] == 1){
                        grid[rc][cc] = 2;
                        q.push({rc, cc});
                        count--;
                    }
                }
            }
            min++;
        }

        if (count > 0) return -1;
        return min;
        
    }
};