class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<pair<int, int>> dir = {{0, 1}, {0,-1}, {1,0}, {-1, 0}};

        queue<pair<int,int>> q;
        q.push({sr, sc});

        while (!q.empty()){
            auto top = q.front();
            q.pop();

            for (auto d: dir){
                int sr = top.first + d.first;
                int sc = top.second + d.second;
                if (sr >= 0 && sr < m && sc >= 0 && sc < n && image[top.first][top.second] == image[sr][sc] && image[sr][sc] != color){
                    q.push({sr, sc});
                }
            }

            image[top.first][top.second] = color;
        }

        return image;
    }
};