vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> res;

    sort(A.begin(), A.end(), [&](Interval &a, Interval &b){
        return a.start < b.start;
    });
    int i = 0, j, m = A[0].end;
    for(j = 1; j < A.size(); j++){
        if(m >= A[j].start)
            m = max(m, A[j].end);
        else{
            res.push_back(Interval(A[i].start, m));
            i = j;
            m = A[j].end;
        }
    }
    res.push_back(Interval(A[i].start, m));
    return res;
}
