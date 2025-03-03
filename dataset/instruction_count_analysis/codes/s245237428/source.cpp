// https://atcoder.jp/contests/abc118/tasks/abc118_d



#include "stdc++.h"



using namespace std;



#define REP(i,n)   for(int i=0; i<(int)(n); i++)

#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')

#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

#define ITR(c,it)  for(auto it = c.begin(); it != c.end(); it++)

#define DUMP2DSTR(a, n, m) REP(_i, n) REP(_j, m) printf("%s%c", a[_i][_j].c_str(), _j + 1 == m ? '\n' : ' '); puts("")



//------------------------------------------------------------------------------

struct match {

  int w;

  string s;

};



bool compare_vd(const match& m1, const match& m2) {

  return m1.s > m2.s;

}



//------------------------------------------------------------------------------

const int N_MAX = 1e4;

const int M_MAX = 9;

const int A_I_MAX = 9;

const int WGT[] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };



int N, M;

int A[M_MAX];



map<int, int> mp;

vector<match> x;



int K;

string dp[M_MAX + 1][N_MAX + 1];

int prv[M_MAX + 1][N_MAX + 1];



map<int, int, greater<int>> ans;



void solve() {

  sort(A, A + M);

  REP(i, M) mp[WGT[A[i]]] = A[i];

  ITR(mp, it) x.push_back({ it->first, to_string(it->second)});

  sort(x.begin(), x.end(), compare_vd);

  K = x.size();



  fill(dp[0], dp[0] + N + 1, "-");

  dp[0][0] = "";

  REP(i, K) {

    int w = x[i].w;

    REP(j, N + 1) {

      string s1 = dp[i][j];

      if (j < w) {

        dp[i + 1][j] = s1;

      } else {

        string s2 = dp[i + 1][j - w];

        if (s2 != "-") s2 += x[i].s;

        if (s2 == "-") {

          dp[i + 1][j] = s1;

        } else if (s1.length() > s2.length()) {

          dp[i + 1][j] = s1;

        } else if (s1.length() == s2.length() ) {

          dp[i + 1][j] = max(s1, s2);

        } else {

          dp[i + 1][j] = s2;

        }

      }

    }

  }



  // DUMP2DSTR(dp, K + 1, N + 1);



  printf("%s\n", dp[K][N].c_str());

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
