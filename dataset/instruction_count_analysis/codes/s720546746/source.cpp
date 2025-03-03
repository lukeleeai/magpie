#include "stdc++.h"

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define ALL(c) (c).begin(), (c).end()

const int INF = 0x3f3f3f3f;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<typename Ch,typename Tr,typename C,typename=decltype(begin(C()))>basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>&os,

const C& c){os<<'[';for(auto i=begin(c);i!=end(c);++i)os<<(i==begin(c)?"":" ")<<*i;return os<<']';}



int a[100];

int e[100];

int r[100];

int dp[101][101];



int main() {

  int d,n;

  while (cin>>d>>n, d||n) {

    REP(i,n) {

      cin >> a[i] >> e[i] >> r[i];

    }

    memset(dp,0x3f,sizeof(dp));

    dp[0][0] = 0;

    REP(i,d) {

      REP(j,101) {

        REP(k,n) {

          if (j >= r[k]) {

            chmin(dp[min(d,i+a[k])][min(100,j+e[k])], dp[i][j] + 1);

          }

        }

      }

    }

    int ans = INF;

    REP(j,101)

      chmin(ans, dp[d][j]);

    if (ans == INF) puts("NA");

    else cout << ans << endl;

  }

}