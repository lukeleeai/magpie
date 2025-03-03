#include <stdio.h>

#include <array>

#include <algorithm>

#include <tuple>

 

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))

#define REP(i, n) FOR(i, 0, n)

 

using lli = long long int;



constexpr int N = 3000;

std::pair<int, int> A[N];

std::array<lli, N+1> R;



int main(void){

    int n, t; scanf("%d%d", &n, &t);

    REP(i, n) scanf("%d%d", &A[i].first, &A[i].second);

    std::sort(A, A+n);

    REP(i, n){

        int a = A[i].first, b = A[i].second;

        int j, e = (t > a) ? t - a : 0;

        for(j = t-1; j >= e; --j) if(R[t] < R[j] + b) R[t] = R[j] + b;

        for(; j >= 0; --j) if(R[j+a] < R[j] + b) R[j+a] = R[j] + b;

    }

    lli res = 0;

    for(int i = 0; i <= t; ++i) if(res < R[i]) res = R[i];

    printf("%lld\n", res);

    return 0;

}


