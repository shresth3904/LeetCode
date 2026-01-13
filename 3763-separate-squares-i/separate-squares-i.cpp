class Solution {
public:
    double getAreabelow(vector<vector<int>>& squares, double y){
        double total_area=0;
        for (auto& sq: squares){
            if (sq[1] >= y) continue;
            else if (sq[1] + sq[2] < y) total_area += (double)sq[2]*sq[2];
            else total_area += (y - sq[1])* sq[2];
        }

        return total_area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int minY = 1e9;
        int maxY = 0;

        double total_area = 0;
        for (auto& sq: squares){
            minY = min(sq[1], minY);
            maxY = max(sq[1]+sq[2], maxY);
            total_area += (double)sq[2]*sq[2];
        }
        double low = minY, high = maxY;
        for (int i = 0; i < 50; i++){
            double mid = low + (high - low)/2.0;
            if (getAreabelow(squares, mid) < total_area/2.0) low = mid;
            else high = mid;
        }

        return high;
    }
};