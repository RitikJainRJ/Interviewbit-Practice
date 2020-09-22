int Solution::solve(vector<int> &A) {
    stack<int> s;
    int i = 0, min_val = INT_MIN;

    while(i < A.size()){
        if(min_val > A[i])
            return false;
        if(s.empty() || A[i] <= s.top())
            s.push(A[i++]);
        else{
            int top = s.top();
            s.pop();
            min_val = top;
        }
    }
    return true;
}
