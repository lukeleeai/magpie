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

ll n, m, k;

map<ll, ll> MAP;

ll num;

void dfs(int cnt) {

  if(cnt == n) {

    MAP[max(1LL, num-k)]++;

  } else {

    FOR(i,1,m+1) {

      num += i;

      dfs(cnt+1);

      num -= i;

    }

  }

}

int main()

{

  ios::sync_with_stdio(false);

  cin.tie(0);

  while(cin>>n>>m>>k,n||m||k) {

    num = 0;

    MAP.clear();

    ll waru = pow(m, n);

    dfs(0);

    double ans = 0;

    for(auto M : MAP) {

      ans += (double)M.first * M.second / waru;

    }

    printf("%.10lf\n", ans);

  }

  return 0;

}