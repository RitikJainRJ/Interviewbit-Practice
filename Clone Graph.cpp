/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#define Node UndirectedGraphNode

void fillmap(Node *u, unordered_set<Node*> &us, unordered_map<Node*, Node*> &um){
    us.insert(u);
    um[u] = new Node(u->label);

    for(auto it = u->neighbors.begin(); it != u->neighbors.end(); it++){
        Node *v = *it;
        if(us.find(v) == us.end())
            fillmap(v, us, um);
    }
}

void generate(Node *u, unordered_set<Node*> &us, unordered_map<Node*, Node*> &um){
    us.insert(u);

    for(auto it = u->neighbors.begin(); it != u->neighbors.end(); it++){
        Node *v = *it;
        um[u]->neighbors.push_back(um[v]);
        if(us.find(v) == us.end())
            generate(v, us, um);
    }
}

Node* Solution::cloneGraph(Node *node) {
    unordered_set<Node*> us;
    unordered_map<Node*, Node*> um;

    fillmap(node, us, um);
    us.clear();
    generate(node, us, um);
    return um[node];
}
