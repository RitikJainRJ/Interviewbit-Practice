int cowsNumber(vector<int> &nums, int min_dist){
    int res = 1, s = nums[0];

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] - s >= min_dist){
            res++;
            s = nums[i];
        }
    }
    return res;
}

int Solution::solve(vector<int> &nums, int k) {
    int min_diff = INT_MAX, n = nums.size(), res = 0;

    sort(nums.begin(), nums.end());
    for(int i = 1; i < n; i++)
        min_diff = min(min_diff, nums[i] - nums[i - 1]);
    int l = min_diff, r = nums[n - 1] - nums[0], m;
    while(l <= r){
        m = (l + r) / 2;
        int c = cowsNumber(nums, m);

        if(c >= k)
            res = m, l = m + 1;
        else
            r = m - 1;
    }
    return res;
}
