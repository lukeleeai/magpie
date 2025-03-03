#include <iostream>

#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

#include <cstring>

#include <deque>

#include <functional>

#include <initializer_list>

#include <math.h>

#include <map>

#include <random>

#include <set>

#include <stack>

#include <tuple>

#include <type_traits>

#include <queue>

#include <vector>





#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))

#define rFOR(i, a, b) for(int (i) = (b); (i) >= (a); --(i))

#define REP(i, n) FOR(i, 0, n)

#define rREP(i, n) rFOR(i, 0, (n-1))

#define SORT(A) std::sort((A).begin(), (A).end())

#define ALL(A) (A).begin(), (A).end()

// 座標圧縮 (for vector) : ソートしてから使うのが一般的 ; SORT(A) => COORDINATE_COMPRESSION(A)

#define COORDINATE_COMPRESSION(A) (A).erase(unique((A).begin(),(A).end()),(A).end())



using lli = long long int;

using pii = std::pair<int, int>;



// グリッド上の縦横移動

constexpr std::array<std::pair<int, int>, 4> dxdy = {

    std::pair<int, int>( 1,  0),

    std::pair<int, int>(-1,  0),

    std::pair<int, int>( 0,  1),

    std::pair<int, int>( 0, -1)

};



void VintOut(std::vector<int>& A){

    const int n = A.size();

    if(n == 0){putchar('\n'); return;}

    printf("%d", A[0]);

    for(int i = 1; i < n; ++i) printf(" %d", A[i]);

    putchar('\n');

}

void VintOut(std::vector<long long int>& A){

    const int n = A.size();

    if(n == 0){ putchar('\n'); return;}

    printf("%lld", A[0]);

    for(int i = 1; i < n; ++i) printf(" %lld", A[i]);

    putchar('\n');

}



template <typename T>

inline bool chmin(T& a, T b){

    if(b < a){ a = b; return true;}

    return false;

}



template <typename T>

inline bool chmax(T& a, T b){

    if(a < b){ a = b; return true;}

    return false;

}



inline bool isIn(int x, int y, int H, int W){

    return 0 <= x and x < H and 0 <= y and y < W;

}

inline bool bitUP(int state, int k){ return (state >> k) & 1; }

inline bool bitUP(long long int state, int k){ return (state >> k) & 1;}



// z-algorithm

template <class T> std::vector<int> z_algorithm(const T &str) {

    const int n = str.size();

    std::vector<int> resOfCP(n); resOfCP[0] = n;

    int i = 1, j = 0;

    while (i < n) {

        while (i + j < n and str[j] == str[i + j]) ++j;

        resOfCP[i] = j;

        if (j == 0) { ++i; continue;}

        int k = 1;

        while (i + k < n and k + resOfCP[k] < j) resOfCP[i + k] = resOfCP[k], ++k;

        i += k; j -= k;

    }

    return resOfCP;

}





// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



constexpr lli inf = 1e18 + 114514;

constexpr int MAX_N = 1e3;

constexpr int MAX_H = 1e4;

std::array<std::array<lli, MAX_H + 1>, MAX_N + 1> DP;



int main(void){

    int H, n; scanf("%d%d", &H, &n);

    for(int i = 0; i <= n; ++i) for(int j = 0; j <= H; ++j) DP[i][j] = inf;

    DP[0][H] = 0;

    REP(i, n){

        int a, b; scanf("%d%d", &a, &b);

        for(int j = 0; j <= H; ++j){

            int nj = j - a; if(nj < 0) nj = 0;

            chmin(DP[i+1][nj], DP[i][j] + b);

            chmin(DP[i+1][j],  DP[i][j]);

        }

        for(int j = H; j >= 0; --j){

            int nj = j - a; if(nj < 0) nj = 0;

            chmin(DP[i+1][nj], DP[i+1][j] + b);

        }

    }

    printf("%lld\n", DP[n][0]);

    

    

    return 0;

}