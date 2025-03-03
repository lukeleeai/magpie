#pragma GCC optimize ("O3")

#include "stdc++.h"

#define ll long long

#define cst first

#define dur second

#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

const int N = 1e5 + 5, M = 2 * N + 5;



int n;

char s[N];

ll dp[N][15];

ll MOD(1e9 + 7);



ll solve(int i, int ba2e){

    if(i == n)return (ba2e == 5);

    ll &ret = dp[i][ba2e];

    if(~ret)return ret;

    ret = 0;

    for(int j = 0 ; j <= 9 && s[i] == '?'; ++j)

        ret = (ret + solve(i + 1, (ba2e * 10 + j) % 13)) % MOD;

    if(s[i] != '?')

        ret = (ret + solve(i + 1, (ba2e * 10 + (s[i] - '0')) % 13)) % MOD;

    return ret;

}

int main(){

    scanf("%s", s);

    n = strlen(s);

    memset(dp, -1, sizeof dp);

    printf("%lld\n", solve(0, 0));

}