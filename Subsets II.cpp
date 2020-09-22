void solve(int i, vector<int> &A, vector<int> &ans, vector<vector<int>> &res){
    res.push_back(ans);

    for(int j = i; j < A.size(); j++){
        ans.push_back(A[j]);
        solve(j + 1, A, ans, res);
        while(j + 1 < A.size() && A[j] == A[j + 1])
            j++;
        ans.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> ans;

    sort(A.begin(), A.end());
    solve(0, A, ans, res);
    return res;
}
