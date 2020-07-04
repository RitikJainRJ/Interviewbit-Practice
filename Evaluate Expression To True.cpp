int Solution::cnttrue(string s) {
    string symbol, op;

    for(int i = 0; i < s.length(); i = i + 2)
        symbol += s[i];
    for(int i = 1; i < s.length(); i = i + 2)
        op += s[i];
    int n = symbol.length();
    int t[n][n], f[n][n];

    for(int i = 0; i < n; i++){
        t[i][i] = symbol[i] == 'T' ? 1 : 0;
        f[i][i] = symbol[i] == 'F' ? 1 : 0;
    }
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;

            t[i][j] = 0, f[i][j] = 0;
            for(int k = i; k < j; k++){
                int tik = t[i][k] + f[i][k];
                int tkj = t[k + 1][j] + f[k + 1][j];

                if(op[k] == '|'){
                    t[i][j] += tik * tkj - f[i][k] * f[k + 1][j];
                    f[i][j] += f[i][k] * f[k + 1][j];
                }
                else if(op[k] == '&'){
                    t[i][j] += t[i][k] * t[k + 1][j];
                    f[i][j] += tik * tkj - t[i][k] * t[k + 1][j];
                }
                else{
                    t[i][j] += t[i][k] * f[k + 1][j] + f[i][k] * t[k + 1][j];
                    f[i][j] += t[i][k] * t[k + 1][j] + f[i][k] * f[k + 1][j];
                }
            }
        }
    }
    return t[0][n - 1];
}
