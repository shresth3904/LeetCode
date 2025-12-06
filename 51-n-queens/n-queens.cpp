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
    
    void gen(int start, vector<vector<string>>& res, vector<string>& curr, int n,int placed){
        if (placed == n){
            res.push_back(curr);
            return;
        }
        for (int i = start; i < n; i++){
            for (int j = 0; j < n; j++){
                if (issafe(curr, i, j)){
                    curr[i][j] = 'Q';
                    gen(i+1, res, curr, n, placed+1);
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
        gen(0, res, curr, n, 0);

        return res;


    }
};