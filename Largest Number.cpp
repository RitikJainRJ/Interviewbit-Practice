string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    string res;
    vector<string> B(n);

    for(int i = 0; i < n; i++)
        B[i] = to_string(A[i]);
    sort(B.begin(), B.end(), [&](string &a, string &b){
        return a + b > b + a;
    });
    if(0 < n && B[0] == "0")
        return "0";
    for(int i = 0; i < n; i++){
        res += B[i];
    }
    return res;
}
