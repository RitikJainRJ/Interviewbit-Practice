#define ll unsigned long long
int Solution::compareVersion(string A, string B) {
    ll n = A.length(), m = B.length();
    ll i = 0, j = 0;

    while(i < n && j < m){
        ll x = 0, y = 0;

        while(isdigit(A[i])){
            x = x * 10 + (A[i] - '0');
            i++;
        }
        i++;
        while(isdigit(B[j])){
            y = y * 10 + (B[j] - '0');
            j++;
        }
        j++;
        if(x != y)
            return x > y ? 1 : -1;
    }
    while(i < n){
        if(isdigit(A[i]) && A[i] != '0')
            return 1;
        i++;
    }
    while(j < m){
        if(isdigit(B[j]) && B[j] != '0')
            return -1;
        j++;
    }
    return 0;
}
