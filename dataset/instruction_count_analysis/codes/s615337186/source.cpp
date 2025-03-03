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

inline

int numb(int a, int b, int c, int n, int k, Vint &Data){

  Vint A(4, 0), B(4, -1);

  REP(i, n){

    A.at(k & 3) += Data.at(i);

    B.at(k & 3)++;

    k >>= 2;

  }

  if(B.at(0) == -1 || B.at(1) == -1 || B.at(2) == -1) return INFi;

  int cost_merge = 10 * (B.at(0) + B.at(1) + B.at(2));

  return abs(a - A.at(0)) + abs(b - A.at(1)) + abs(c - A.at(2)) + cost_merge;

}



int main(void){

  int n, a, b, c; cin >> n >> a >> b >> c;

  Vint L(n); vREP(ele, L) cin >> ele;

  // cout << "L :"; vREP(ele, L) cout << ele << " "; cout << "\n";

  int res = INFi;

  REP(i, 1 << (2 * n)) chmin(res, numb(a, b, c, n, i, L));

  cout << res << '\n';

  return 0;

}