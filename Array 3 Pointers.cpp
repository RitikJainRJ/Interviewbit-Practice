int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int res = INT_MAX;
    int i = 0, j = 0, k = 0;

    while(1){
        if(i == A.size() || j == B.size() || k == C.size())
            break;
        res = min(res, max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])}));
        int temp = min({A[i], B[j], C[k]});
        if(temp == A[i])    i++;
        else if(temp == B[j])   j++;
        else    k++;
    }
    return res;
}
