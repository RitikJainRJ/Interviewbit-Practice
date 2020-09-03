/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void preorder(TreeNode *root, int B, TreeNode *&t, unordered_map<TreeNode*, TreeNode*> &um){
    if(!root)   return;
    else{
        if(root->val == B)
            t = root;
        if(root->left)
            um[root->left] = root;
        if(root->right)
            um[root->right] = root;
        preorder(root->left, B, t, um);
        preorder(root->right, B, t, um);
    }
}

int Solution::solve(TreeNode* A, int B) {
    unordered_map<TreeNode*, TreeNode*> um;
    unordered_set<TreeNode*> us;
    queue<TreeNode*> q;
    TreeNode *t = nullptr;
    int res = -1;

    um[A] = nullptr;
    preorder(A, B, t, um);
    us.insert(nullptr);
    us.insert(t);
    q.push(t);
    while(!q.empty()){
        int size = q.size();

        while(size--){
            TreeNode *f = q.front();
            q.pop();

            if(us.find(f->right) == us.end())
                us.insert(f->right), q.push(f->right);
            if(us.find(f->left) == us.end())
                us.insert(f->left), q.push(f->left);
            if(us.find(um[f]) == us.end())
                us.insert(um[f]), q.push(um[f]);
        }
        res++;
    }
    return res;
}
