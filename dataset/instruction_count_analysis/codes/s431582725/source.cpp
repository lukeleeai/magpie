#include <algorithm>

#include <cstdio>

#include <iostream>

#include <map>

#include <cmath>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <string>

#include <vector>

#include <stdlib.h>

#include <stdio.h>

#include <bitset>

#include <cstring>

#include <deque>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

#define CLR(mat) memset(mat, 0, sizeof(mat))

typedef long long ll;

int main()

{

  ll n,m,k;

  while(cin>>n>>m>>k,n||m||k) {

    ll dp[n+1][n*m+1]; CLR(dp);

    dp[0][0] = 1;

    FOR(i,0,n) {

      FOR(j,0,m*i+1) {

        FOR(t,1,m+1) {

          dp[i+1][j+t] += dp[i][j];

        }

      }

    }

    double ans = 0;

    ll waru = pow(m, n);

    FOR(i,0,n*m+1) {

      ans += (double)dp[n][i] * max(1LL, i-k) / waru;

    }

    printf("%.10lf\n", ans);

  }

}