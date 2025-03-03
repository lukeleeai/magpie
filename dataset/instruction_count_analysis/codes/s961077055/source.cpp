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

vector<double> x(50), y(50);



double dist(int i, int j){

  return hypot(x[j]-x[i], y[j]-y[i]);

}



double mid;

bool f(double xx, double yy){

  REP(i, N){

    if(hypot(xx-x[i], yy-y[i]) > mid+1e-10) return false;

  }

  return true;

}



bool check(){

  bool flag = true;

  REP(i, N){

    FOR(j, i+1, N){

      if(dist(i, j) > mid*2+1e-10) continue;

      double d = sqrt(mid*mid-dist(i, j)*(dist(i, j))/4);

      double mx = (x[i]+x[j])/2;

      double my = (y[i]+y[j])/2;

      double px = (y[i]-y[j])/dist(i, j)*d;

      double py = -(x[i]-x[j])/dist(i, j)*d;

      if(f(mx+px, my+py)) return true;

      if(f(mx-px, my-py)) return true;

      flag = false;

    }

  }

  return false;

}



signed main() {

  cin >> N;



  REP(i, N) cin >> x[i] >> y[i];



  double ok = 4000;

  double ng = 0;

  REP(i, 50){

    mid = (ok+ng)/2;

    if(check()) ok = mid;

    else ng = mid;

  }



  cout << ok << "\n";



  return 0;

}