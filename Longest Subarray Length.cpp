int Solution::solve(vector<int> &A) {
    int res = 0, curr = 0;
    unordered_map<int, int> um;

    for(int i = 0; i < A.size(); i++){
        curr += (A[i] == 0 ? -1 : 1);
        if(curr == 1)
            res = max(res, i + 1);
        if(um.find(curr - 1) != um.end())
            res = max(res, i - um[curr - 1]);
        if(um.find(curr) == um.end())
            um[curr] = i;
    }
    return res;
}
