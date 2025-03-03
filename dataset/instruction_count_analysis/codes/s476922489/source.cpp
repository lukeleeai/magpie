#include <cstdio>

#include <array>

#include <algorithm>

#include <tuple>



constexpr int N = 2e5;

std::array<std::pair<int, int>, N> A;

std::array<long long int, N + 1> S; 



int readInt(void){

    char c;

    do{c = getchar_unlocked();} while(c < '0');

    int res = 0;

    do{res = 10 * res + c - '0'; c = getchar_unlocked();} while(c >= '0');

    return res;

}



int main(void){

    int n, d, a; n = readInt(); d = readInt(); a = readInt(); d <<= 1;

    for(int i = 0; i < n; ++i){

        A[i].first = readInt();

        A[i].second = readInt();

    }

    std::sort(A.begin(), A.begin() + n);

    long long int res = 0, dec = 0;

    int r = 0;

    for(int l = 0; l < n; ++l){

        while(r < n and A[r].first - A[l].first <= d) r++;

        dec -= S[l]; A[l].second -= dec;

        if(A[l].second <= 0) continue;

        long long int p = (A[l].second / a) + (!!(A[l].second % a));

        dec += p * a; S[r] += p * a; res += p;

    }

    printf("%lld\n", res);

    return 0;

}