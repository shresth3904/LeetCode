class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int total_time = 0;
        for (int i = 1; i < n; i++){
            int x = abs(points[i][0]-points[i-1][0]);
            int y = abs(points[i][1]-points[i-1][1]);

            int time = min(x, y) + abs(x-y);
            total_time += time;
        }

        return total_time;
    }
};