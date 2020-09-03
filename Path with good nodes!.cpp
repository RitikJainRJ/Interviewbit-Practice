class Graph{
private:
    int n;
    vector<int> *adj;
    vector<int> values;

    void dfs(int u, vector<bool> &visited, int c, int &res){
        visited[u] = true;
        bool flag = false;

        c -= values[u];
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            int v = *it;
            if(!visited[v]){
                flag = true;
                dfs(v, visited, c, res);
            }
        }
        if(!flag && c >= 0)
            res++;
    }

public:
    Graph(int n, vector<int> &values){
        this->n = n;
        this->values = values;
        adj = new vector<int>[n];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int solve(int c){
        vector<bool> visited(n, false);
        int res = 0;

        dfs(0, visited, c, res);
        return res;
    }
};

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    Graph g(n, A);

    for(int i = 0; i < B.size(); i++)
        g.addEdge(B[i][0] - 1, B[i][1] - 1);
    return g.solve(C);
}
