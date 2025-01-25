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

#define MP make_pair

#define PB push_back

#define F first

#define S second

#define INF 1 << 30

#define EPS 1e-10



typedef pair<int, int> pi;

typedef pair<int, pi> pii;

typedef vector<int> vi;

typedef queue<int> qi;

typedef long long ll;



int Q;

int dp[64][64][64];



int dfs(int c, int a, int n){

  if(dp[c][a][n] >= 0) return dp[c][a][n];

  int res = 0;

  if(c > 0 && a > 0 && n > 0) res = max(res, dfs(c-1, a-1, n-1)+1);

  if(c > 1 && a > 0) res = max(res, dfs(c-2, a-1, n)+1);

  if(c > 2) res = max(res, dfs(c-3, a, n)+1);

  return dp[c][a][n] = res;

}



int main(){

  cin >> Q;

  rep(i, Q){

    memset(dp, -1, sizeof(dp));

    int c, a, n;

    cin >> c >> a >> n;

    int res = 0;

    while(c > 8 && a > 4 && n > 0){

      res++;

      c--;

      a--;

      n--;

    }



    while(c > 8 && a > 4){

      res++;

      c-=2;

      a--;

    }



    while(c > 8){

      res++;

      c-=3;

    }

    res += dfs(c, a, n);

    printf("%d\n", res);

  }

  return 0;

}