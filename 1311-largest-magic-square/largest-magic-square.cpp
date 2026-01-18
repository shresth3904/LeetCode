class Solution {
public:
    bool verify(vector<vector<int>>& grid, int k, int row, int col){
        int sum = 0; for (int i = row; i < row+k; i++) sum += grid[i][col];

        for (int n = 0; n < k; n++){
            int curr = 0; for (int i = row; i < row+k; i++) curr += grid[i][col+n];
            if (curr != sum) return false;

            int curr2 = 0; for (int i = col; i < col+k; i++) curr2 += grid[row+n][i];
            if (curr2 != sum) return false;
        }

        int diag1 = 0; for (int i = 0; i < k; i++) diag1 += grid[row+i][col+i];
        if (diag1 != sum) return false;

        int diag2 = 0; for (int i = 0; i < k; i++) diag2 += grid[row+k-i-1][col+i];
        if (diag2 != sum) return false;

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int len = min(m, n);
        int max_side = 1;
        for (int k = 2; k <= len; k++){
            
            for (int i = 0; i <= m-k; i++){
                bool flag = false;
                for (int j = 0; j <= n -k; j++){
                    if (verify(grid, k, i, j)) {
                        flag = true;
                        max_side = k;
                        break;
                    }
                }
                if (flag) break;
            }
        }

        return max_side;
    }
};