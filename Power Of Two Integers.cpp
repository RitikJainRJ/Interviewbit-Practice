#define ll unsigned long long
int Solution::isPower(int A){
    if(A == 1)
        return 1;

    for(ll i = 2; i * i <= A; i++){
        for(ll j = i; j <= A; j = j * i)
            if(j == A)
                return 1;
    }
    return 0;
}
