#define pii pair<int, int>

vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    unordered_map<int, pii> um;
    vector<int> res({INT_MAX, INT_MAX, INT_MAX, INT_MAX});

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            int sum = A[i] + A[j];

            if(um.find(sum) == um.end())
                um[sum] = {i, j};
            else{
                int a = um[sum].first, b = um[sum].second;
                if(a != i && a != j && b != i && b != j){
                    vector<int> temp = {a, b, i, j};
                    if(res > temp)
                        res = temp;
                }
            }
        }
    return res;
}
