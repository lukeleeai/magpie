#include"stdc++.h"



using namespace std;



#define int long long



const int N = 305;

int n, mod, K, dp[N][N], C[N][N], psum[N][N];



void sieve(){

    for(int i = 0; i < N; ++i) C[0][i] = C[i][i] = 1;

    for(int i = 1; i < N; ++i){

        for(int j = 1; j < i; ++j){

            C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % mod;

        }

    }

}



signed main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> K >> mod;

    sieve();



    for(int i = 0; i <= K; ++i) dp[1][i] = 1, psum[1][i] = (i + 1) % mod;



    for(int i = 2; i <= n + 1; ++i){

        for(int j = 0; j <= K; ++j){

            for(int k = 1; k < i; ++k){

                dp[i][j] += ((dp[i - k][j] * (psum[k][K] - psum[k][j])) % mod * C[k - 1][i - 2]) % mod; dp[i][j] %= mod;

            }

            if(j) psum[i][j] = (dp[i][j] + psum[i][j - 1]) % mod;

        }

    }



     cout << (dp[n + 1][0] + mod) % mod;



    return 0;

}
