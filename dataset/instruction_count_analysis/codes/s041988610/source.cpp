#include <stdio.h>

#include <array>

#include <bitset>



constexpr int K = 10;

constexpr int L = 1 << K;

constexpr int N = 100;

constexpr int inf = 2e9 + 334;

std::array<std::bitset<K>, N> D;

std::array<std::array<int, K+1>, N> P;

std::array<int, N> C;



int main(void){

    int n; scanf("%d", &n);

    for(int i = 0; i < n; ++i){

        for(int j = 0; j < K; ++j){

            getchar(); D[i][j] = getchar() - '0';

        }

    }

    for(int i = 0; i < n; ++i){

        for(int j = 0; j <= K; ++j) scanf("%d", &P[i][j]);

    }

    int res = -inf;

    for(int x = 1; x < L; ++x){

        for(int i = 0; i < n; ++i) C[i] = 0;

        for(int j = 0; j < K; ++j) if((x >> j) & 1){

            for(int i = 0; i < n; ++i) if(D[i][j]) C[i]++;

        }

        int d = 0;

        for(int i = 0; i < n; ++i) d += P[i][C[i]];

        if(res < d) res = d;

    }

    printf("%d\n", res);

    return 0;

}