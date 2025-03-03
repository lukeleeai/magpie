#include <cmath>

#include <cstdio>

#include <cstdlib>

#include <cstring>



#include <algorithm>

#include <bitset>

#include <complex>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <vector>



#include <cassert>

#include <functional>



typedef long long ll;

using namespace std;



#ifndef LOCAL

#define debug(x) ;

#else

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;



template<typename T1, typename T2>

ostream &operator<<(ostream &out, const pair<T1, T2> &p) {

  out << "{" << p.first << ", " << p.second << "}";

  return out;

}



template<typename T>

ostream &operator<<(ostream &out, const vector<T> &v) {

  out << '{';

  for (const T &item : v) out << item << ", ";

  out << "\b\b}";

  return out;

}

#endif



#define mod 1000000007 //1e9+7(prime number)

#define INF 1000000000 //1e9

#define LLINF 2000000000000000000LL //2e18

#define SIZE 200010



typedef double P_type; //座標(integer or real)

typedef double G_real; //実数の戻り値(float or double or long double)

typedef complex<P_type> P;

const G_real P_eps = 1e-8; //整数の時はゼロ



namespace std {

  template<class T>

  bool operator<(const complex<T> &a, const complex<T> &b) {

    return abs(a.real() - b.real()) < P_eps ? a.imag() + P_eps < b.imag() : a.real() + P_eps < b.real();

  }

};



P rotate(P p, double theta) {

  return p * P(cos(theta), sin(theta));

}



//内積

P_type dot(P a, P b) {

  return (a * conj(b)).real();

}



//外積

P_type cross(P a, P b) {

  return (conj(a) * b).imag();

}



//反時計回り

int ccw(P a, P b, P c) {

  if (cross(b - a, c - a) > P_eps) return 1; //COUNTER_CLOCKWISE(center:a)

  if (cross(b - a, c - a) < -P_eps) return -1; //CLOCKWISE(center:a)

  if (dot(b - a, c - a) < -P_eps) return -2; //c -> a -> b

  if (dot(a - b, c - b) < -P_eps) return 2; //a -> b -> c

  return 0; //a -> c -> b

}



/*

// 偏角 [-pi, pi]

// complex<int|ll> 使用時の std::arg の代わり

G_real arg(P p) {

  return atan2(imag(p), real(p));

}

*/



/* ベクトルa, bの角度 */

// ({0, 1}, {1, 0}) => 90, ({0, 1}, {-1, -1}) => -135

G_real degree(P a, P b) {

  return atan2(cross(b, a), dot(b, a)) / M_PI * 180;

}



/* 線分abと点cの距離 */

G_real distanceSP(P a, P b, P c) {

  if (dot(b - a, c - a) < P_eps) return abs(c - a);

  if (dot(a - b, c - b) < P_eps) return abs(c - b);

  return abs(cross(b - a, c - a)) / abs(b - a);

}



/* 直線abと点cの距離 */

G_real distanceLP(P a, P b, P c) {

  return abs(cross(b - a, c - a)) / abs(b - a);

}



/* 円の点包含判定 */

bool isContainedCP(P c, P_type r, P p) {

  //return abs(c - p) < r - P_eps; //円周上を含まない

  return abs(c - p) <= r + P_eps; //円周上を含む

}



/* 円の円包含判定 (円1の内部に円2が存在するか) */

bool isContainedCC(P c1, P_type r1, P c2, P_type r2) {

  return abs(c1 - c2) + r2 < r1 - P_eps; //接する場合を含まない

  //return abs(c1 - c2) + r2 <= r1 + P_eps; //接する場合を含まない

}



/* 直線交差判定 */

bool isIntersectedLL(P a1, P a2, P b1, P b2) {

  return abs(cross(a1 - a2, b1 - b2)) > P_eps;

}



/* 線分交差判定 */

bool isIntersectedSS(P a1, P a2, P b1, P b2) {

  //線分a と 直線b

  int a = ccw(b1, b2, a1);

  int b = ccw(b1, b2, a2);



  //線分b と 直線a

  int c = ccw(a1, a2, b1);

  int d = ccw(a1, a2, b2);



  return a * b <= 0 && c * d <= 0; // T字を除く時は (** < 0)

}



/* 直線A線分B交差判定 */

bool isIntersectedLS(P a1, P a2, P b1, P b2) {

  int a = ccw(a1, a2, b1);

  int b = ccw(a1, a2, b2);



  // 直線上のとき a or b = 0 or -2 or 2

  return (a % 2) * (b % 2) <= 0; // T字を除く時は (** < 0)

}



/* 円交差判定 */

bool isIntersectedCC(P c1, G_real r1, P c2, P_type r2) {

  G_real dist = abs(c1 - c2);



  return abs(r1 - r2) <= dist + P_eps && dist - P_eps <= r1 + r2; //外接内接を含む

  //return abs(r1 - r2) < dist - P_eps && dist + P_eps < r1 + r2; //外接内接を除く

}



/* 円直線交差判定 */

bool isIntersectedCL(P c, G_real r, P a1, P a2) {

  return distanceLP(a1, a2, c) <= r + P_eps; //接する場合を含まない場合 < r - P_eps

}



/* 円線分交差判定 */

bool isIntersectedCS(P c, P_type r, P a1, P a2) {

  return (!isContainedCP(c, r, a1) || !isContainedCP(c, r, a2)) &&

         distanceLP(a1, a2, c) <= r + P_eps; //接する場合を含まない場合 < r - P_eps

}



/* 直線/線分交点 */

vector<P> getCrosspointLL(P a1, P a2, P b1, P b2) {

  //assert(isIntersectedLL(a1, a2, b1, b2));

  P a = a2 - a1;

  P b = b2 - b1;

  return {a1 + a * cross(b, b1 - a1) / cross(b, a)};

}



vector<P> getCrosspointSS(P a1, P a2, P b1, P b2) {

  //assert(isIntersectedSS(a1, a2, b1, b2));

  return getCrosspointLL(a1, a2, b1, b2);

}



/* 円交点 */

vector<P> getCrosspointCC(P c1, P_type r1, P c2, P_type r2) {

  //assert(isIntersectedCC(c1, r1, c2, r2));



  P_type dist = abs(c1 - c2);

  P_type a = acos((r1 * r1 + dist * dist - r2 * r2) / (2 * r1 * dist));

  return {c1 + polar(r1, arg(c2 - c1) + a), c1 + polar(r1, arg(c2 - c1) - a)};

}



/* 円直線交点 */

vector<P> getCrosspointCL(P c, P_type r, P a1, P a2) {

  if (!isIntersectedCL(c, r, a1, a2)) return {};



  P base1 = a2 - a1;

  P proj = a1 + base1 * dot(c - a1, base1) / norm(base1); //射影

  P e = (a2 - a1) / abs(a2 - a1);

  P base2 = sqrt(r * r - norm(proj - c));

  return {proj - e * base2, proj + e * base2};

}



/* 円線分交点 */

vector<P> getCrosspointCS(P c, P_type r, P a1, P a2) {

  if (!isIntersectedCS(c, r, a1, a2)) return {};



  vector<P> res;

  for (P p : getCrosspointCL(c, r, a1, a2))

    if (dot(a1 - p, a2 - p) <= P_eps) res.push_back(p);

  return res;

}



/* 多角形-点包含 */

bool isContainedPolyP(vector<P> &g, P p) {

  int n = g.size();

  bool f = false;

  for (int i = 0; i < n; i++) {

    P a = g[i] - p, b = g[(i + 1) % n] - p;

    if (abs(cross(a, b)) < P_eps && dot(a, b) < P_eps) return true; //辺上

    if (a.imag() > b.imag()) swap(a, b);

    if (a.imag() < P_eps && P_eps < b.imag() && cross(a, b) > P_eps) f = !f;

  }

  return f; //内部 or 外部

}



/* 射影(直線abとpからの垂線との交点) */

P getProject(P a, P b, P p) {

  P base = b - a;

  return a + base * dot(p - a, base) / norm(base);

}



/* 反射(直線abを対称軸としたpの線対称の位置) */

P getReflection(P a, P b, P p) {

  return p + (getProject(a, b, p) - p) * (P_type)2.0;

}



/* 多角形面積 */

G_real getAreaPoly(vector<P> &g) {

  P_type res = 0;

  for (int i = 0; i < (int)g.size(); i++)

    res += cross(g[i], g[(i + 1) % g.size()]);

  return abs(res / 2.0);

}



/* 円の共通面積 */

G_real getAreaCC(P c1, P_type r1, P c2, P_type r2) {

  G_real d = abs(c1 - c2);

  if (r1 + r2 <= d + P_eps) {

    return 0.0;

  } else if (d <= abs(r1 - r2) + P_eps) {

    G_real r = min(r1, r2);

    return r * r * M_PI;

  } else {

    G_real res = 0;

    for (int i = 0; i < 2; i++) {

      G_real rc = (G_real)(norm(c1 - c2) + r1 * r1 - r2 * r2) / (2 * d * r1);

      G_real theta = acos(rc) * 2;

      res += (theta - sin(theta)) * r1 * r1 / 2;

      swap(r1, r2);

      swap(c1, c2);

    }

    return res;

  }

}



/* 円-直線(中心との三角形) 共通面積 */

G_real getAreaCS(P c, P_type r, P a1, P a2) {

  if (min({abs(a1 - a2), abs(c - a1), abs(c - a2), r}) <= P_eps) return 0;



  G_real res = 0;

  vector<P> vec = {a1};

  for (auto p : getCrosspointCS(c, r, a1, a2)) vec.push_back(p);

  vec.push_back(a2);



  for (int i = 0; i + 1 < (int)vec.size(); i++) {

    P p1 = vec[i] - c, p2 = vec[i + 1] - c;

    if (max(abs(p1), abs(p2)) <= r + P_eps)

      res += cross(p1, p2) / 2.0;

    else

      res += r * r * arg(conj(p1) * p2) / 2.0;

  }



  return res;

}



/* 円-多角形共通面積 */

G_real getAreaPolyC(vector<P> &g, P c, P_type r) {

  G_real res = 0;

  for (int i = 0; i < (int)g.size(); i++)

    res += getAreaCS(c, r, g[i], g[(i + 1) % g.size()]);

  return abs(res);

}



/* 凸多角形の切断 */

// 直線Aで切断し、a1からa2方向に見たときに直線Aの左側にできる凸多角形を返す

vector<P> convexCut(const vector<P> &g, P a1, P a2) {

  vector<P> res;

  P prev = *g.rbegin();

  for (P now : g) {

    if (ccw(a1, a2, prev) != -1) res.push_back(prev);

    int c = ccw(a1, a2, prev) * ccw(a1, a2, now);

    if (-4 < c && c < 0) {

      res.push_back(getCrosspointLL(prev, now, a1, a2)[0]);

    }

    prev = now;

  }

  return res;

}



/* 凸多角形の直径(最遠頂点対間距離) */

// 反時計回りのみ

G_real convexDiameter(const vector<P> &g) {

  int N = g.size(), is = 0, js = 0;

  for (int i = 1; i < N; i++) {

    if (imag(g[i]) > imag(g[is])) is = i;

    if (imag(g[i]) < imag(g[js])) js = i;

  }



  G_real maxd = abs(g[is] - g[js]);



  int i, maxi, j, maxj;

  i = maxi = is;

  j = maxj = js;



  do {

    if (cross(g[(i + 1) % N] - g[i], g[(j + 1) % N] - g[j]) >= 0)

      j = (j + 1) % N;

    else

      i = (i + 1) % N;



    if (abs(g[i] - g[j]) > maxd) {

      maxd = abs(g[i] - g[j]);

      maxi = i;

      maxj = j;

    }

  } while (i != is || j != js);



  return maxd; /* farthest pair is {maxi, maxj}. */

}



int N, K;

int x[SIZE], y[SIZE], c[SIZE];

P p[SIZE];



bool check(P_type r) {

  vector<P> points;



  for (int i = 0; i < N; i++) {

    for (int j = 0; j < i; j++) {

      if (!isIntersectedCC(p[i], r / c[i], p[j], r / c[j])) continue;



      auto cps = getCrosspointCC(p[i], r / c[i], p[j], r / c[j]);

      for (auto cp : cps) points.push_back(cp);

    }

  }



  for (int i = 0; i < N; i++)

    points.push_back(p[i]);



  for (auto cp : points) {

    int counter = 0;

    for (int i = 0; i < N; i++) {

      counter += isContainedCP(p[i], r / c[i], cp);

    }

    if (counter >= K) return true;

  }



  return false;

}



int main() {

  scanf("%d%d", &N, &K);



  for (int i = 0; i < N; i++) {

    scanf("%d%d%d", x + i, y + i, c + i);

    p[i] = P(x[i], y[i]);

  }



  double l = 0, r = 1e7;



  for (int _ = 0; _ < 100; _++) {

    double mid = (l + r) / 2;



    if (check(mid)) {

      r = mid;

    } else {

      l = mid;

    }

  }



  printf("%.10lf\n", l);



  return 0;

}
