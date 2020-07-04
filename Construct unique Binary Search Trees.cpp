vector<TreeNode*> generate(int s, int e){
    vector<TreeNode*> res;
    if(s > e){
        res.push_back(nullptr);
        return res;
    }
    if(s == e){
        res.push_back(new TreeNode(s));
        return res;
    }
    for(int i = s; i <= e; i++){
        vector<TreeNode*> left = generate(s, i - 1);
        vector<TreeNode*> right = generate(i + 1, e);
        for(int j = 0; j < left.size(); j++){
            for(int k = 0; k < right.size(); k++){
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> Solution::generateTrees(int n) {
    if(n == 0)  return vector<TreeNode*>();
    return generate(1, n);
}
