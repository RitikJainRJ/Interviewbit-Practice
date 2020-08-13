class Graph{
private:
    int n;
    vector<int> *arr;

    int _dia(int u, int &res){
        int m1 = 0, m2 = 0;
        if(arr[u].size() == 0)
            return 1;
        for(int v = 0; v < arr[u].size(); v++){
            int t = _dia(arr[u][v], res);
            if(m1 < t)
                m2 = m1, m1 = t;
            else if(m2 < t)
                m2 = t;
        }
        if(1 + m1 + m2 > res)
            res = 1 + m1 + m2;
        return 1 + m1;
    }

public:
    Graph(int n){
        this->n = n;
        arr = new vector<int>[n];
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
    }

    int diameter(int s){
        int res = n == 1 ? 1 : 0;

        _dia(s, res);
        return res - 1;
    }
};

int Solution::solve(vector<int> &A) {
    int n = A.size(), root;
    Graph g(n);

    for(int i = 0; i < n; i++)
        if(A[i] == -1)  root = i;
        else    g.addEdge(A[i], i);
    return g.diameter(root);
}
