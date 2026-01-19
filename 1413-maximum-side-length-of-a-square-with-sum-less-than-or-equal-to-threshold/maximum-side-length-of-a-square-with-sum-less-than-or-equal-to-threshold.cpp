class Solution {
public:
    void prefixSum(vector<vector<int>>& mat, vector<vector<int>>& res){
        int sum = 0;
        for (int i = 0; i < mat.size(); i++){
            sum += mat[i][0];
            res[i][0] = sum;
        }
        sum = 0;
        for (int i = 0; i < mat[0].size(); i++){
            sum += mat[0][i];
            res[0][i] = sum;
        }

        for (int i = 1; i < mat.size(); i++){
            for (int j = 1; j < mat[0].size(); j++){
                res[i][j] = res[i-1][j] + res[i][j-1] - res[i-1][j-1] + mat[i][j];
            }
        }
    }


    int findSum(vector<vector<int>>& res, int row, int col, int k){
        int big_sq = res[row+k][col+k];
        int upper_sq = (row > 0)? res[row-1][col+k]: 0;
        int side_sq = (col > 0)? res[row+k][col-1]: 0;
        int corner = (row > 0 && col > 0)? res[row-1][col-1]: 0;

        return big_sq + corner - side_sq - upper_sq; 
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        int len = min(m, n);

        vector<vector<int>> res(m, vector<int>(n, 0));
        prefixSum(mat, res);


        for (int k = len; k > 0; k--){
            for (int i = 0; i <= m-k; i++){
                for (int j = 0; j <= n-k; j++){
                    if (findSum(res, i, j, k-1) <= threshold) return k;
                }
            }
        }

        return 0;
    }
};