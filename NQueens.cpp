bool isSafe(int r, int c, vector<string> &board){
    for(int i = 0; i < c; i++)
        if(board[r][i] == 'Q')
            return false;
    int i = r, j = c;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q')
            return false;
        i--, j--;
    }
    i = r, j = c;
    while(i < board.size() && j >= 0){
        if(board[i][j] == 'Q')
            return false;
        i++, j--;
    }
    return true;
}

void nQueens(int c, vector<string> &board, vector<vector<string>> &res){
    if(c == board.size()){
        res.push_back(board);
        return;
    }

    for(int i = 0; i < board.size(); i++){
        if(isSafe(i, c, board)){
            board[i][c] = 'Q';
            nQueens(c + 1, board, res);
            board[i][c] = '.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    nQueens(0, board, res);
    return res;
}
