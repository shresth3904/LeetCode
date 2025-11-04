class Solution {
public:

    bool check(vector<vector<char>>& board, int step, string word, int i, int j){
        if (step == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (word[step] != board[i][j] || board[i][j] == '#') return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool res =  check(board, step+1, word, i+1, j)|
                    check(board, step+1, word, i-1, j)|
                    check(board, step+1, word, i, j+1)|
                    check(board, step+1, word, i, j-1);
        board[i][j] = temp;

        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        char c = word[0];
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == c && check(board, 0, word, i, j)){
                    return true;
                }
            }
        }

        return false;
    }
};