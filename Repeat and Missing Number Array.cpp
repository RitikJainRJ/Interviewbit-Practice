#define ll long long
vector<int> Solution::repeatedNumber(const vector<int> &nums) {
    ll sum1 = 0, sum2 = 0, res;

    for(ll i = 0; i < nums.size(); i++){
        sum1 += (i + 1 - (ll)nums[i]);
        sum2 += ((i + 1) * (i + 1) - (ll)nums[i] * (ll)nums[i]);
    }
    res = sum2 / sum1;
    return vector<int>({(res - sum1) / 2, (res + sum1) / 2});
}

