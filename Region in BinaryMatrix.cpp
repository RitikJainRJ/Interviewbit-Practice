int dfs(int x, int y, vector<vector<int>> &A){
    int xMove[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int yMove[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int res = 1;

    A[x][y] = -1;
    for(int i = 0; i < 8; i++){
        int nx = x + xMove[i];
        int ny = y + yMove[i];
        if(0 <= nx && nx < A.size() && 0 <= ny && ny < A[0].size() && A[nx][ny] == 1)
            res += dfs(nx, ny, A);
    }
    return res;
}

int Solution::solve(vector<vector<int> > &A) {
    int res = 0;

    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A[0].size(); j++)
            if(A[i][j] == 1)
                res = max(res, dfs(i, j, A));
    return res;
}
