vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<int> res;
    unordered_map<int, unordered_set<int>> um;

    for(int i = 0; i < A.size(); i++)
        um[A[i]].insert(0);
    for(int i = 0; i < B.size(); i++)
        um[B[i]].insert(1);
    for(int i = 0; i < C.size(); i++)
        um[C[i]].insert(2);
    for(auto it = um.begin(); it != um.end(); it++)
        if(it->second.size() > 1)
            res.push_back(it->first);
    sort(res.begin(), res.end());
    return res;
}
