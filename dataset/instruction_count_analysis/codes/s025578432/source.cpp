#include <iostream>

#include <algorithm>

#include <iomanip>

#include <cmath>

using namespace std;



int n;

pair<double, double> ps[222];



int main() {

  cin >> n;

  for(int i = 0; i < n; ++i) cin >> ps[i].first >> ps[i].second;

  sort(ps, ps + n, [](auto a, auto b) {

      return atan2(a.first, a.second) < atan2(b.first, b.second);

  });

  for(int i = 0; i < n; ++i) ps[i + n] = ps[i];



  double ans = 0.0;

  for(int L = 0; L < n; ++L) {

    for(int R = L; R < L + n; ++R) {

      double x = 0.0, y = 0.0;

      for(int i = L; i <= R; ++i) x += ps[i].first, y += ps[i].second;

      ans = max(ans, x*x + y*y);

    }

  }

  cout << fixed << setprecision(15) << sqrt(ans);

  return 0;

}