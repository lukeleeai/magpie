#include"stdc++.h"



using namespace std;

const int mod = 1e9 + 7;

int qs[(int)1e5 + 5], inv[(int)1e5 + 5];

int pow(int val, int idx){

    if(idx == 0) return 1;

    if(idx == 1) return val;

    int k = pow(val, idx >> 1);

    k = (1LL * k * k) %  mod;

    if(idx & 1) k = (1LL * k * val) % mod;

    return k;

}

int main(){

    int n, pre, x;

    scanf("%d %d",&n,&pre);

    for(int i = 1; i < n;i++){

        scanf("%d", &x);

        qs[i] = qs[i-1] + x - pre;

        pre = x;

    }

    int fac = 1;

    for(int i = 1;i < n;i++){

        fac = (1LL * fac * i) % mod;

        inv[i] = i == 1 ? 1 : pow(i, mod - 2);

    }

    int ans = 0;

    for(int i = 1; i < n; i++){

        ans += (1LL * (qs[n - 1] - qs[i-1]) * (1LL * fac * inv[i] % mod)) % mod;

        ans = ans >= mod ? ans - mod : ans;

    }

    printf("%d",ans);







}
