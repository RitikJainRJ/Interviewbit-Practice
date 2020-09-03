void dfs(int x, int y, vector<vector<int>> &A, vector<vector<int>> &water){
    int xMove[] = {-1, 0, 1, 0};
    int yMove[] = {0, 1, 0, -1};

    water[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + xMove[i];
        int ny = y + yMove[i];

        if(0 <= nx && nx < A.size() && 0 <= ny && ny < A[0].size() && A[x][y] <= A[nx][ny] && water[nx][ny] == 0)
            dfs(nx, ny, A, water);
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> blue(n, vector<int>(m, 0)), red(n, vector<int>(m, 0));
    int res = 0;

    for(int i = 0; i < n; i++)
        dfs(i, 0, A, blue);
    for(int i = 1; i < m; i++)
        dfs(0, i, A, blue);
    for(int i = 0; i < n; i++)
        dfs(i, m - 1, A, red);
    for(int i = 0; i < m; i++)
        dfs(n - 1, i, A, red);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(blue[i][j] && red[i][j])
                res++;
    return res;
}
