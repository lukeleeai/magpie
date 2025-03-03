#include <cstdio>

 

using namespace std;

 

#define REP(i,n)   for(int i=0; i<(int)(n); i++)

#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

 

const int N_MAX = 50;

const int DP0 = 2500;

 

typedef long long ll;

 

int N, A;

int x[N_MAX];

 

ll dp[DP0 * 2 + 1];

 

void solve() {

  dp[DP0] = 1;

  REP(i, N) {

    x[i] -= A;

    if (x[i] < 0) {

      for (int j = -DP0; j <= DP0 + x[i]; j++) {

        dp[DP0 + j] += dp[DP0 + j - x[i]];

      }

    } else {

      for(int j = DP0; j >= -DP0 + x[i]; j--) {

        dp[DP0 + j] += dp[DP0 + j - x[i]];

      }

    }

  }

  printf("%lld\n", dp[DP0] - 1);

}

 

void input() {

  scanf("%d%d", &N, &A);

  REP(i, N) scanf("%d", x + i);

}

 

int main() {

  input();

  solve();

  return 0;

}