#define pii pair<int, int>
int Solution::solve(int A, int B, vector<string> &C) {
    int xMove[] = {-1, 0, 1, 0};
    int yMove[] = {0, 1, 0, -1};
    char dir[] = {'U', 'R', 'D', 'L'};
    int x, y, d, nx, ny;
    vector<vector<int>> dp(A, vector<int>(B, INT_MAX));
    queue<pii> q;

    dp[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()){
        pii f = q.front();
        q.pop();
        x = f.first, y = f.second, d = dp[x][y];

        for(int i = 0; i < 4; i++){
            nx = x + xMove[i];
            ny = y + yMove[i];

            int t = dir[i] == C[x][y] ? dp[x][y] : dp[x][y] + 1;
            if(0 <= nx && nx < A && 0 <= ny && ny < B && t < dp[nx][ny]){
                dp[nx][ny] = t;
                q.push({nx, ny});
            }
        }
    }
    return dp[A - 1][B - 1];
}
