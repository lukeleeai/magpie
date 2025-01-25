#include <iostream>

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <vector>

#include <string>

#include <map>

#include <set>

#include <queue>

#include <stack>

#include <algorithm>



using namespace std;



#define rep(i,j) REP((i), 0, (j))

#define REP(i,j,k) for(int i=(j);(i)<(k);++i)

#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))

#define ALL(v) (v).begin(), (v).end()

#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))

#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)

#define SQ(x) ((x)*(x))

#define Mod(x, mod) (((x)+(mod)%(mod))

#define MP make_pair

#define PB push_back

#define F first

#define S second

#define INF 1LL << 60

#define EPS 1e-10

#define MOD 1000000007



typedef pair<int, int> P;

typedef vector<int> vi;

typedef queue<int> qi;

typedef long long ll;



vector<P>St[256];

int N, M;

ll dp[256][16][128];



ll dfs(int n, int x, int m){

  if(n>=N-1) return 0;

  if(n>=N-2 && m) return 0;

  ll &res = dp[n][x][m];

  if(res >= 0) return res;

  res = INF;

  int pos = St[n][x].first ,slip = St[n][x].second;

  rep(i, St[n+1].size()){

      P tar = St[n+1][i];

      res = min(res, dfs(n+1, i, m)+(ll)(slip+tar.second)*(ll)(abs(pos-tar.first)));

  }

  if(m && n < N-2){

    rep(i, St[n+2].size()){

      P tar = St[n+2][i];

      res = min(res, dfs(n+2, i, m-1)+(ll)(slip+tar.second)*(ll)(abs(pos-tar.first)));

    }

  }

  //  cout << n << " " << x << " "<< m <<" " << res << endl;

  return res;

}



int main(){

  while(scanf("%d%d", &N, &M) && N){

    int k, x, d;

    memset(dp, -1, sizeof(dp));

    rep(i,N) St[i].clear();

    rep(i, N){

      scanf("%d", &k);

      rep(j,k){

	scanf("%d%d", &x, &d);

	St[i].push_back(P(x, d));

      }

    }

    

    ll res = INF;

    rep(i, St[0].size()) res = min(res, dfs(0, i, M));

    if(M) rep(i, St[1].size()) res = min(res, dfs(1, i, M-1));



    printf("%lld\n", res);

  }

  return 0;

}