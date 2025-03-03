// https://atcoder.jp/contests/abc118/tasks/abc118_d



#include "stdc++.h"



using namespace std;



#define REP(i,n)   for(int i=0; i<(int)(n); i++)

#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')

#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

#define ITR(c,it)  for(auto it = c.begin(); it != c.end(); it++)



//------------------------------------------------------------------------------

struct match { int w, v, c; };



bool compare_vd(const match& m1, const match& m2) {

  return m1.v > m2.v;

}



//------------------------------------------------------------------------------

const int N_MAX = 1e4;

const int M_MAX = 9;

const int A_I_MAX = 9;

const int WGT[] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

const int INF = 1e9;



int N, M;

int A[M_MAX];



map<int, int> mp;

vector<match> x;



int K;

int dp[N_MAX + 1];



void solve() {

  sort(A, A + M);

  REP(i, M) mp[WGT[A[i]]] = A[i];

  ITR(mp, it) x.push_back({ it-> first, it-> second, 0 });

  sort(x.begin(), x.end(), compare_vd);

  K = x.size();



  fill(dp, dp + N + 1, -INF);

  dp[0] = 0;

  FOR(i, 1, N) {

    REP(j, K) {

      int w = x[j].w;

      if (i >= w) dp[i] = max(dp[i], dp[i - w] + 1);

    }

  }



  // DUMP(dp, N + 1);



  int i = N;

  while (i > 0) {

    REP(j, K) {

      int w = x[j].w;

      if (i >= w && dp[i - w] == dp[i] - 1) {

        printf("%d", x[j].v);

        i = i - w;

        break;

      }

    }

  }

  puts("");



}



void input() {

  scanf("%d%d", &N, &M);

  REP(i, M) scanf("%d", A + i);

}



int main() {

  input();

  solve();

  return 0;

}
