#include <iostream>

#include <algorithm>

#include <map>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <string.h>

#include <vector>

#include <queue>

#include <cmath>

#include <bitset>

#include <complex>

#include <functional>

#include <numeric>

#include <iomanip>



// output

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');

#define YES cout << "YES" << endl

#define Yes cout << "Yes" << endl

#define NO cout << "NO" << endl

#define No cout << "No" << endl

// utility

#define ALL(i) (i).begin(), (i).end()

#define FOR(i, a, n) for(int i=(a);i<(n);++i)

#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)

#define REP(i, n) for(int i=0;i<int(n);++i)

#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)

#define IN(a, x, b) (a<=x && x<b)

#define OUT(a, x, b) (x<a || b<=x)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



// type/const

#define int ll

using ll = long long;

using ull = unsigned long long;

using ld = long double;

const int MOD = 1000000007;

/* const int MOD = 998244353; */

const int INF = 1e18;

const double PI = acos(-1);



using namespace std;

struct INIT { INIT(){

  cin.tie(0); ios::sync_with_stdio(false);

  cout << fixed << setprecision(10);

}}INIT;



int N, A, B, C;

vector<string> s(100010), ans(100010);



void g(char s, char t){

  if(s == 'A') A--; if(t == 'A') A++;

  if(s == 'B') B--; if(t == 'B') B++;

  if(s == 'C') C--; if(t == 'C') C++;

}

void f(int i, char s, char t){

  ans[i] = s;

  g(t, s);

}



void dfs(int n){

  if(A < 0 || B < 0 || C < 0) return;

  if(n == N){

    Yes;

    REP(i, N) cout << ans[i] << "\n";

    exit(0);

  }



  REP(i, 2){

    f(n, s[n][i], s[n][1-i]);

    dfs(n+1);

    g(s[n][i], s[n][1-i]);

  }

}



signed main() {

  cin >> N >> A >> B >> C;



  REP(i, N) cin >> s[i];



  dfs(0);



  No;



  return 0;

}