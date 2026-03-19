class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 'X' || visited[i][j]) continue;
                stack<pair<int, int>> st;
                vector<pair<int, int>> log;
                st.push({i, j});
                visited[i][j] = true;
                bool enclosed = true;
                while (!st.empty()){
                    auto ele = st.top();
                    log.push_back(ele);
                    st.pop();
                    for (auto d: dir){
                        int sr = ele.first + d.first;
                        int sc = ele.second + d.second;
                        if (sr >= 0 && sc >= 0 && sr < m && sc < n){
                            if (board[sr][sc] == 'O' && !visited[sr][sc]){
                                st.push({sr, sc});
                                visited[sr][sc] = true;
                            }
                        } else {
                            enclosed = false;
                        }
                    }
                }

                if (enclosed){
                    for (auto ele: log) board[ele.first][ele.second] = 'X';
                }
            }
        }
    }
};