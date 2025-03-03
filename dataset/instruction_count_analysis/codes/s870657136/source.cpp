#include <stdio.h>

#include <string.h>

#include <algorithm>

#include <iostream>

#include <math.h>

#include <assert.h>

#include <vector>

#include <queue>

#include <string>

#include <map>

#include <set>



using namespace std;

typedef long long ll;

typedef unsigned int uint;

typedef unsigned long long ull;

static const double EPS = 1e-9;

static const double PI = acos(-1.0);



#define REP(i, n) for (int i = 0; i < (int)(n); i++)

#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)

#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)

#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)

#define MEMSET(v, h) memset((v), h, sizeof(v))



int n;

double rs[10];



int main() {

  while (scanf("%d", &n) > 0) {

    set<vector<int> > visit;

    REP(i, n) { scanf("%lf", &rs[i]); }

    sort(rs, rs + n);

    double ans = 0.0;

    do {

      for (int last = 3; last <= n; last++) {

        {

          vector<int> target;

          REP(i, last) { target.push_back(rs[i]); }

          if (visit.count(target)) { continue; }

          REP(iter, 2) {

            REP(i, last) {

              visit.insert(target);

              rotate(target.begin(), target.begin() + 1, target.end());

            }

            reverse(target.begin(), target.end());

          }

        }

        double left = 0.0;

        double right = PI;

        REP(iter, 100) {

          double mid = (left + right) / 2.0;

          double lans = rs[0] * rs[1] * sin(mid) / 2.0;

          double sum = mid;

          for (int i = 1; i < last; i++) {

            double v = rs[0] * rs[1] / rs[i] / rs[(i + 1) % last] * cos(mid);

            if (v > 1) { v = 1; }

            if (v < -1) { v = -1; }

            double theta = acos(v);

            sum += theta;

            lans += rs[i] * rs[(i + 1) % last] * sin(theta) / 2.0;

          }

          if (sum > 2 * PI) {

            right = mid;

          } else {

            left = mid;

          }

          if (fabs(sum - 2 * PI) < EPS) { ans = max(ans, lans); }

        }

      }

    } while (next_permutation(rs, rs + n));

    printf("%.8f\n", ans);

  }

}