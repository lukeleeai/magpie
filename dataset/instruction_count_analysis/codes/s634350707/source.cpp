#include "stdc++.h"

using namespace std;



using lli = long long int;

using Vint = vector<int>;

using Vlli = vector<lli>;

using Wint = vector<Vint>;

using Wlli = vector<Vlli>;

using pii = pair<int, int>;

using pll = pair<lli, lli>;



const int MOD = 1e9 + 7;

const int INFi = 2e9 + 1;

const lli INFl = (lli)(9e18) + 1;

const vector<pii> DXDY = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};



#define FOR(i, a, b) for(int (i) = (a); (i) < (b); (i)++)

#define FOReq(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

#define rFOR(i, a, b) for(int (i) = (b); (i) >= (a); i--)

#define REP(i, n) FOR(i, 0, n)

#define rREP(i, n) rFOR(i, 0, (n-1))

#define vREP(i, vec) for(auto &(i) : (vec))





template <class T> inline int argmin(vector<T> vec){return min_element(vec.begin(), vec.end()) - vec.begin();}

template <class T> inline int argmax(vector<T> vec){return max_element(vec.begin(), vec.end()) - vec.begin();}

template <class T> inline void chmax(T &a, T b){a = max(a, b);}

template <class T> inline void chmin(T &a, T b){a = min(a, b);}





// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





int main(void){

  int n; cin >> n;

  int F[n][5][2], P[n][10], gettmp;

  REP(i, n) REP(j, 5) REP(k, 2) cin >> F[i][j][k];

  REP(i, n) REP(j, 11) cin >> P[i][j];

  int res = -INFi;

  FOR(i, 1, 1 << 10){

    int profit = 0;

    REP(k, n){

      int bit_search = 1, numb = 0;

      REP(j, 5){

        if(F[k][j][0] == 1 && (i & bit_search) != 0) numb++;

        bit_search <<= 1;

      }

      REP(j, 5){

        if(F[k][j][1] == 1 && (i & bit_search) != 0) numb++;

        bit_search <<= 1;

      }

      profit += P[k][numb];

    }

    chmax(res, profit);

  }

  cout << res << '\n';

  return 0;

}