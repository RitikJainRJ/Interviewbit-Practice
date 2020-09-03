class TrieNode{
public:
    unordered_map<char, TrieNode*> um;
    int freq;
    bool isEnd;

    TrieNode(){
        freq = 0;
        isEnd = false;
    }
};

void insert(TrieNode *&root, string &s){
    TrieNode *t = nullptr;

    if(!root)
        root = new TrieNode();
    t = root;
    for(int i = 0; i < s.length(); i++){
        if(t->um.find(s[i]) == t->um.end())
            t->um[s[i]] = new TrieNode();
        t = t->um[s[i]];
        t->freq++;
    }
    t->isEnd = true;
}

string search(TrieNode *root, string &s){
    TrieNode *t = nullptr;
    string res;

    t = root;
    for(int i = 0; i < s.length(); i++){
        if(t->freq == 1)
            break;
        res.push_back(s[i]);
        t = t->um[s[i]];
    }
    return res;
}

vector<string> Solution::prefix(vector<string> &A) {
    TrieNode *root = nullptr;
    vector<string> res;

    for(int i = 0; i < A.size(); i++)
        insert(root, A[i]);
    for(int i = 0; i < A.size(); i++)
        res.push_back(search(root, A[i]));
    return res;
}
