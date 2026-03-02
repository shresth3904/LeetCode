class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> rows;
        int n = grid.size();

        for (int i = 0; i < n; i++){
            int count = 0;
            for (int j = n-1; j >= 0; j--){
                if (grid[i][j] == 1) break;
                count++;
            }
            rows.push_back(n-count-1);
        }

        int swaps = 0;
        for (int i = 0; i < n; i++){
            int fndindx = -1;

            for (int j = i; j < n; j++){
                if (rows[j] <= i) {
                    fndindx = j;
                    break;
                }
            }

            if (fndindx == -1) return -1;

            for (int k = fndindx; k > i; k--){
                swap(rows[k], rows[k-1]);
                swaps++;
            }
        }

        return swaps;
    }
};