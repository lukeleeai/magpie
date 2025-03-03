// Code by H~$~C

#include "stdc++.h"

using namespace std;



static const int Maxn = 55;

static const double EPS = 1e-9;



int n;



struct point {

  double x, y;

} a[Maxn];

inline double get_dist(double x, double y) {

  double mx = 0;

  for (int i = 1; i <= n; ++i) {

    double now = sqrt((x - a[i].x) * (x - a[i].x) + (y - a[i].y) * (y - a[i].y));

    mx = max(mx, now);

  }

  return mx;

}



double f(double x) {

  double l = 0, r = 1000;

  while (r - l > EPS) {

    double lmid = l + (r - l) / 3.0;

    double rmid = r - (r - l) / 3.0;

    if (get_dist(x, lmid) > get_dist(x, rmid)) l = lmid;

    else r = rmid;

  }

  return get_dist(x, l);

}



int main() {

  scanf("%d", &n);

  for (int i = 1; i <= n; ++i)

    scanf("%lf%lf", &a[i].x, &a[i].y);

  double l = 0, r = 1000;

  while (r - l > EPS) {

    double lmid = l + (r - l) / 3.0;

    double rmid = r - (r - l) / 3.0;

    if (f(lmid) > f(rmid)) l = lmid;

    else r = rmid;

  }

  printf("%.7lf\n", f(l));

  return 0;

}
