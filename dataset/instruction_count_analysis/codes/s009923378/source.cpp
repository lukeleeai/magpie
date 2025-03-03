#include <iostream>

#include <limits>

#include <cfenv>

#include <cmath>

#include <algorithm>

#include <array>

#include <bitset>

#include <cstring>

#include <map>

#include <stack>

#include <set>

#include <tuple>

#include <queue>

#include <vector>

#include <cmath>

#include <random>

#include <math.h>

#include <list>

#include <random>

#include <functional>





#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))

#define REP(i, n) FOR(i, 0, n)

#define rREP(i, n) for(int (i) = (n) - 1; (i) >= 0; --(i))

#define ALL(TheArray) TheArray.begin(), TheArray.end()



using lli = long long int;

using pii = std::pair<int, int>;



template <class T> inline bool chmax(T& a, T b){

    if(a < b){a = b; return true;}

    return false;

}

template <class T> inline bool chmin(T& a, T b){

    if(a > b){a = b; return true;}

    return false;

}







// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~









// D[i] = 最初の注文からi分終了時で得られる最大の満足

constexpr int N = 3000;

std::array<lli, 2 * N + 1> D;

std::vector<std::pair<int, int>> A;

std::vector<bool> S;











int main(void){

    int n, t; scanf("%d%d", &n, &t);

    A.resize(n); REP(i, n) scanf("%d%d", &A[i].first, &A[i].second);

    std::sort(A.begin(), A.end());

    REP(i, n){

        int x = A[i].first, y = A[i].second;

        for(int j = t - 1; j >= 0; --j){

            if(D[j + x] < D[j] + y) D[j + x] = D[j] + y;

        }

    }

    lli res = 0;

    for(lli p : D) if(res < p) res = p;

    printf("%lld\n", res);

    

    return 0;

}


