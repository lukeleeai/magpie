#include <stdio.h>

#include <string.h>

#include <algorithm>

#include <iostream>

#include <math.h>

#include <assert.h>

#include <vector>

#include <complex>

#include <queue>



using namespace std;

typedef long long ll;

typedef complex<double> Point;

static const double EPS = 1e-9;

static const double PI = acos(-1.0);



#define REP(i, n) for (int i = 0; i < (int)(n); i++)

#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)

#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)

#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)

#define DEC(i, s) for (int i = (s); i >= 0; i--)



#define SIZE(v) (int)((v).size())

#define MEMSET(v, h) memset((v), h, sizeof(v))

#define FIND(m, w) ((m).find(w) != (m).end())



int n;

double R;

Point points[3000];



struct Node {

  Point p;

  double w;

  int bound;

  Node(Point p, double w, int bound) : p(p), w(w), bound(bound) {;}

  bool operator<(const Node &rhs) const {

    return bound < rhs.bound;

  }

};



int main() {

  R = 1.0;

  while (scanf("%d", &n), n) {

    priority_queue<Node> que;

    REP(i, n) {

      double x, y;

      scanf("%lf %lf", &x, &y);

      points[i] = Point(x, y);

      que.push(Node(points[i], R, 10000));

    }

    int ans = 1;

    while (!que.empty()) {

      Node node = que.top();

      que.pop();

      if (node.bound <= ans) { break; }

      int lans = 0;

      int nbound = 0;

      REP(i, n) {

        double dist = abs(points[i] - node.p);

        if (dist < R) {

          lans++;

          nbound++;

        } else if (dist < R + node.w * 1.41421356) {

          nbound++;

        }

      }

      ans = max(ans, lans);

      if (nbound <= ans) { continue; }

      const double dx[4] = { -1, -1, 1, 1 };

      const double dy[4] = { -1, 1, -1, 1 };

      double nw = node.w / 2.0;

      REP(i, 4) {

        double nx = node.p.real() + nw * dx[i];

        double ny = node.p.imag() + nw * dy[i];

        que.push(Node(Point(nx, ny), nw, nbound));

      }

    }

    printf("%d\n", ans);

  }

}