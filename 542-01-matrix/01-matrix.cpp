class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++){
            for (int j = 0; j <n; j++){
                if (mat[i][j] == 0) q.push({i, j});
            }
        }

        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        vector<vector<int>> res(m, vector<int>(n, -1));
        int lvl = 0;
        while (!q.empty()){
            int k = q.size();
            for (int i = 0; i < k; i++){
                auto top = q.front();
                q.pop();
                if (res[top.first][top.second] == -1) res[top.first][top.second] = lvl;
                else res[top.first][top.second] = min(res[top.first][top.second], lvl);

                for (auto d: dir){
                    int sr = top.first + d[0];
                    int sc = top.second + d[1];

                    if (sr >= 0 && sc >= 0 && sr < m && sc < n && mat[sr][sc] == 1 && res[sr][sc] == -1){
                        q.push({sr, sc});
                    }
                }
            }
            lvl++;
        }

        return res;
    }
};