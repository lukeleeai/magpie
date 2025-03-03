#include "stdc++.h"

using namespace std;



using ll = long long;

using ii = pair<int, int>;

using vi = vector<int>;

#define all(v) begin(v), end(v)



const int N = 102;



int dp[N][N][N+N];

int n, m;

char s[N][N];



int f(int i, int j, int k) {

  int& ret = dp[i][j][k];

  if(ret != -1) return ret;

  if(i == n && j == m) {

    if((s[n][m] == '#') ^ (k&1)) {

      if(k) ret = 0;

      else ret = 1;

    } else {

      ret = 0;

    }

    return ret;

  }

  ret = 1e8;

  if(i != n) {

    if((s[i][j] == '#') ^ (k&1)) {

      if(k) ret = min(ret, f(i+1, j, k-1));

      ret = min(ret, 1 + f(i+1, j, k+1));

    } else {

      ret = min(ret, f(i+1, j, k));

    }

  }

  if(j != m) {

    if((s[i][j] == '#') ^ (k&1)) {

      if(k) ret = min(ret, f(i, j+1, k-1));

      ret = min(ret, 1 + f(i, j+1, k+1));

    } else {

      ret = min(ret, f(i, j+1, k));

    }

  }

  return ret;

}

int main(int argc, char const *argv[])

{

#ifdef LOCAL

  freopen("in", "r", stdin);

#endif

  scanf("%d %d", &n, &m);

  for(int i = 1; i <= n; ++i) {

    scanf("%s", s[i]+1);

  }

  memset(dp, -1, sizeof dp);

  printf("%d\n", f(1, 1, 0));

  return 0;

}