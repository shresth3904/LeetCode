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

    bool isValid(vector<vector<int>>& res, int k, int threshold){
        int m = res.size();
        int n = res[0].size();
        if (k == 0) return false;
        for (int i = 0; i <= m-k; i++){
            for (int j = 0; j <= n-k; j++){
                int big_sq = res[i+k-1][j+k-1];
                int upper_sq = (i > 0)? res[i-1][j+k-1]: 0;
                int side_sq = (j > 0)? res[i+k-1][j-1]: 0;
                int corner = (i > 0 && j > 0)? res[i-1][j-1]: 0;

                int total =  big_sq + corner - side_sq - upper_sq;
                if (total <= threshold) return true;
            }
        }

        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        int len = min(m, n);

        vector<vector<int>> res(m, vector<int>(n, 0));
        prefixSum(mat, res);


        int left = 1, right = len;
        int out = 0;
        while (left <= right){
            int k = left + (right - left)/2;
            if (isValid(res, k, threshold)){
                out = k;
                left = k+1;
            }
            else right = k -1;
            
        }

        return out;
    }
};

