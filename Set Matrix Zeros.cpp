#define pii pair<int, int>
void Solution::setZeroes(vector<vector<int>> &A) {
    vector<pii> arr;
    unordered_set<int> us1, us2;
    int m = A.size(), n = A[0].size();

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(A[i][j] == 0)    arr.push_back({i, j});
    for(int i = 0; i < arr.size(); i++)
        us1.insert(arr[i].first), us2.insert(arr[i].second);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(us1.find(i) != us1.end() || us2.find(j) != us2.end())
                A[i][j] = 0;
}
