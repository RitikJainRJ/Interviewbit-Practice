int knapsack(int total, const vector<int> &fill, const vector<int> &cost){
    int n = fill.size();
    int dp[n + 1][total + 1];

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 1; i <= total; i++)
        dp[0][i] = INT_MAX;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= total; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - fill[i - 1] >= 0 && dp[i][j - fill[i - 1]] != INT_MAX)
                dp[i][j] = min(dp[i][j], cost[i - 1] + dp[i][j - fill[i - 1]]);
        }
    return dp[n][total];
}

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int res = 0;

    for(int i = 0; i < A.size(); i++)
        res += knapsack(A[i], B, C);
    return res;
}
