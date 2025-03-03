#include <iostream>

#include <sstream>

#include <string>

#include <algorithm>

#include <vector>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <cassert>



using namespace std;



#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)

#define REP(i,n) FOR(i,0,n)

#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)



template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }



typedef long long ll;

const int INF = 100000000;

const double EPS = 1e-8;

const int MOD = 1000000007;

int N;

string s, g;

int dp[1<<16][16];

int dfs(int S, int u){

  if(S == (1<<N) - 1) return 0;

  if(dp[S][u] != -1) return dp[S][u];

  int res = INF;

  REP(i, N)REP(j, N) if(i != j && (S >> i & 1) == 0 && (S >> j & 1) == 0 && g[i] != g[j]){

    res = min(res, abs(u - i) + abs(i - j) + dfs(S | 1 << i | 1 << j, j));

  }

  return dp[S][u] = res;

}

int main(){

  while(cin>>N && N){

    cin>>s>>g;

    REP(S, 1<<N) REP(p, N) dp[S][p] = -1;

    int S = 0;

    REP(i, N) if(s[i] == g[i]) S |= 1<<i;

    int ans = INF;

    REP(i, N) ans = min(ans, dfs(S, i));

    cout<<ans<<endl;

  }

  return 0;

}