#define ll unsigned long long
ll countPainters(vector<int> &nums, ll total){
    ll res = 1, sum = 0;

    for(ll i = 0; i < nums.size(); i++){
        sum += nums[i];
        if(sum > total){
            res++;
            sum = nums[i];
        }
    }
    return res;
}

int Solution::paint(int k, int u, vector<int> &h) {
    ll imax = 0, sum = 0, res = 0;

    for(ll i = 0; i < h.size(); i++)
        sum += h[i], imax = max(imax, (ll)h[i]);

    ll l = imax, r = sum;
    while(l <= r){
        ll m = (l + r) / 2;
        ll c = countPainters(h, m);

        if(c <= k)
            res = m, r = m - 1;
        else
            l = m + 1;
    }
    return (res * u) % 10000003;
}
