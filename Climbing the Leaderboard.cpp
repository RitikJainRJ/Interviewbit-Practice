#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &scores, int l, int r, int x){
    int m;

    while(l <= r){
        m = (l + r) / 2;
        if(scores[m] == x)
            return m;
        else if(scores[m] > x)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

void leaderboard(vector<int> &scores, vector<int> &alice){
    auto it = unique(scores.begin(), scores.end());
    int l = 0, r = distance(scores.begin(), it) - 1;

    for(int i = 0; i < alice.size(); i++){
        cout << binary_search(scores, 0, r, alice[i]) + 1 << " ";
    }
}

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> scores(n), alice(m);

        for(int i = 0; i < n; i++)
            cin >> scores[i];
        for(int i = 0; i < m; i++)
            cin >> alice[i];
        leaderboard(scores, alice);
        cout << endl;
    }
    return 0;
}
