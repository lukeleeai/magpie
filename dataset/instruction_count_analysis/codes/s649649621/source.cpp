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

template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }

template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }



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



int N; 

vector<int> X, Y;



double g(double x, double y){

  double ret = 0;

  REP(i, N){

    chmax(ret, hypot(X[i]-x, Y[i]-y));

  }

  return ret;

}

double f(double x){

  double y1 = 0;

  double y2 = 1000;

  REP(i, 100){

    double m1 = (y1*2+y2*1)/3;

    double m2 = (y1*1+y2*2)/3;

    if(g(x, m1) > g(x, m2)) y1 = m1;

    else y2 = m2;

  }

  return g(x, y1);

}

signed main() {

  cin >> N;



  X.resize(N); Y.resize(N);

  REP(i, N) cin >> X[i] >> Y[i];



  double x1 = 0;

  double x2 = 1000;

  REP(i, 100){

    double m1 = (x1*2+x2*1)/3;

    double m2 = (x1*1+x2*2)/3;

    if(f(m1) > f(m2)) x1 = m1;

    else x2 = m2;

  }



  cout << f(x1) << "\n";



  return 0;

}