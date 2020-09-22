int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*> it1, it2;
    TreeNode *t = nullptr;

    t = A;
    while(t)
        it1.push(t), t = t->left;
    t = A;
    while(t)
        it2.push(t), t = t->right;
    while(it1.top() != it2.top()){
        int sum = it1.top()->val + it2.top()->val;

        if(sum == B)
            return 1;
        else if(sum < B){
            t = it1.top()->right;
            it1.pop();
            while(t)
                it1.push(t), t = t->left;
        }
        else{
            t = it2.top()->left;
            it2.pop();
            while(t)
                it2.push(t), t = t->right;
        }
    }
    return 0;
}
