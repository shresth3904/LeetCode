class Solution {
public:
    bool issafe(vector<string>& curr, int row, int col){
        for (int i = 0; i < curr[0].size(); i++){
            if (curr[row][i] == 'Q') return false;
        }

        for (int i = 0; i < curr.size(); i++){
            if (curr[i][col] == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if (curr[i][j] == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j < curr[0].size(); i--, j++){
            if (curr[i][j] == 'Q') return false;
        }

        return true;
    }
    void fillspace(vector<vector<int>>& mat, int x, int y, int op){
        for (int i = 0; i < mat.size(); i ++){
            for (int j = 0; j < mat[0].size(); j++){
                bool linex = i == x;
                bool liney = j == y;
                bool rightD = i-j == x-y;
                bool leftD = i+j == x+y;
                if (linex || liney || rightD || leftD) mat[i][j] += op;
            }
        }
        
    }
    void gen(int start, vector<vector<string>>& res, vector<string>& curr, int n,int placed, vector<vector<int>>& mat){
        if (placed == n){
            res.push_back(curr);
            return;
        }
        for (int i = start; i < mat.size(); i++){
            for (int j = 0; j < mat[0].size(); j++){
                if (issafe(curr, i, j)){
                    curr[i][j] = 'Q';
                    gen(i+1, res, curr, n, placed+1, mat);
                    curr[i][j] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string str = "";
        for (int i = 0; i < n; i++) str += '.';
        vector<string> curr(n, str);

        vector<vector<int>> mat(n, vector<int> (n, 0));

        gen(0, res, curr, n, 0, mat);

        return res;


    }
};