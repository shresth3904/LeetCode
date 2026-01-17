class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long max_area = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int bx = max(bottomLeft[i][0], bottomLeft[j][0]);
                int by = max(bottomLeft[j][1], bottomLeft[i][1]);
                int tx = min(topRight[i][0], topRight[j][0]);
                int ty = min(topRight[j][1], topRight[i][1]);

                if (bx < tx && by < ty){
                    int len = min(tx-bx, ty - by);
                    max_area = max(max_area, (long long)len*len);
                }
            }
        }

        return max_area;
    }
};