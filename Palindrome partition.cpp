void solve(int i, string &A, vector<vector<bool>> &dp, vector<string> &ans, vector<vector<string>> &res){
    if(i == A.length()){
        res.push_back(ans);
        return;
    }

    for(int j = i; j < A.length(); j++){
        if(dp[i][j]){
            ans.push_back(A.substr(i, j - i + 1));
            solve(j + 1, A, dp, ans, res);
            ans.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string A) {
    int n = A.length();
    vector<vector<bool>> dp(n, vector<bool>(n));
    vector<vector<string>> res;
    vector<string> ans;

    for(int i = 0; i < n; i++)
        dp[i][i] = true;
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            if(l == 2)
                dp[i][j] = A[i] == A[j];
            else
                dp[i][j] = A[i] == A[j] && dp[i + 1][j - 1];
        }
    }
    solve(0, A, dp, ans, res);
    return res;
}
