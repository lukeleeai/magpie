// #define _GLIBCXX_DEBUG // for STL debug (optional)

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <string>

#include <cstring>

#include <deque>

#include <list>

#include <queue>

#include <stack>

#include <vector>

#include <utility>

#include <algorithm>

#include <map>

#include <set>

#include <complex>

#include <cmath>

#include <limits>

#include <cfloat>

#include <climits>

#include <ctime>

#include <cassert>

#include <numeric>

#include <fstream>

#include <functional>

#include <bitset>

using namespace std;

using ll = long long int;

using int64 = long long int;

 

template<typename T> void chmax(T &a, T b) {a = max(a, b);}

template<typename T> void chmin(T &a, T b) {a = min(a, b);}

template<typename T> void chadd(T &a, T b) {a = a + b;}

 

int dx[] = {0, 0, 1, -1};

int dy[] = {1, -1, 0, 0};

const int INF = 1LL << 29;

const ll LONGINF = 1LL << 60;

const ll MOD = 1000000007LL;



int dp1[310][310], dp2[310];

int solve_testcase() {

    int N; scanf("%d", &N);

    if(N == 0) return 1;

    vector<int> A(N);

    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    

    fill(dp1[0], dp1[N+1], false);

    for(int i=0; i<N; i++) {

        dp1[i][i] = true;

    }

    for(int d=2; d<=N; d++) {

        for(int l=0; l<N-d+1; l++) {

            int r = l + d;

            if(abs(A[l] - A[r-1]) <= 1 and dp1[l+1][r-1]) dp1[l][r] = true;



            if(r - l >= 4) {

                for(int k=l+2; k<=r-2; k++) {

                    if(dp1[l][k] and dp1[k][r]) dp1[l][r] = true;

                }

            }

        }

    }



    fill(dp2, dp2 + N + 1, -1);

    dp2[0] = 0;

    for(int i=0; i<N; i++) {

        chmax(dp2[i+1], dp2[i]);

        for(int j=i+1; j<=N; j++) {

            if(!dp1[i][j]) continue;

            chmax(dp2[j], dp2[i] + (j - i));

        }

    }

    printf("%d\n", dp2[N]);

    return 0;

}



int main() {

    while(!solve_testcase());

    return 0;

}


