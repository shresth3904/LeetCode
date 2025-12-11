class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                if (board[row][col] == '.') continue;
                char focus = board[row][col];

                for (int i = 0; i < 9; i++){
                    if (board[row][i] == focus && i != col) return false;
                    if (board[i][col] == focus && i != row) return false;
                    int x = (row/3)*3 + i/3;
                    int y = (col/3)*3 + i%3;
                    if (board[x][y] == focus) {
                        if (x == row && y == col) continue;
                        else return false;
                    };
                }
            }
        }

        return true;
    }
};