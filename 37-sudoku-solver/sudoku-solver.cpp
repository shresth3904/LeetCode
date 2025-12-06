class Solution {
public:
    bool isValid(char num, vector<vector<char>>& board, int row, int col){
        for (int i = 0; i < 9; i++){
            if (board[row][i] == num) return false;
        }
        for (int i = 0; i < 9; i++){
            if (board[i][col] == num) return false;
        }

        int x = row/3;
        int y = col/3;

        for (int i = x*3 ; i < x*3 + 3; i++){
            for (int j = y*3; j < y*3 +3; j++){
                if (board[i][j] == num) return false;
            }
        }

        return true;
    }
    bool gen(vector<vector<char>>& board){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.'){
                    for (int num = 1; num <= 9; num++){
                        if (isValid('0'+num, board, i, j)){
                            board[i][j] = '0'+num;
                            if (gen(board) == true) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        gen(board);
    }
};