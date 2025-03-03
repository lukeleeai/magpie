#include"stdc++.h"

#define MAXN 100010

const long long M = 1000000007;

using namespace std;

long long dp[MAXN];

long long N, K;



int pot(long long a, long long b){

    long long ans = 1;

    while(b){

        if(b&1){

            ans = (ans * a) % M;

        }

        a = (a * a) % M;

        b >>= 1;

    }

    return ans;

}

int main(){

    ios::sync_with_stdio(0);

    cin.tie(0);

    N = 3;

    cin >> K;

    long long ans = 0;

    for(int i = K; i > 0; i--){

        dp[i] = pot(K / i, N);

        for(int j = i+i; j <= K; j += i){

            dp[i] -= dp[j];

        }

        dp[i] = ((dp[i] % M) + M) % M;

        ans += i * dp[i];

        ans %= M;

    }

    

    ans = ((ans % M) + M) % M;

    cout << ans << "\n";

    return 0;

}