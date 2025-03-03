#include <iostream>

#include <algorithm>

#include <cmath>

using namespace std;



constexpr double EPS = 1e-6;



inline double sq(double x) { return x*x; }



struct point {

    double x, y;

    point() {}

    point(double x, double y): x(x), y(y) {}



    point operator + (const point& o) const { return point(x+o.x, y+o.y); }

    point operator - (const point& o) const { return point(x-o.x, y-o.y); }

    point operator * (const double a) const { return point(x*a, y*a); }

    point operator / (const double a) const { return point(x/a, y/a); }

};



double fabs(point a) { return sqrt(a.x*a.x + a.y*a.y); }

double dist(point a, point b) { return fabs(a - b); }



int N;

point P[300];



int solve() {

    int ans = 1;

    for (int i = 0; i < N; ++i) {

        for (int j = i+1; j < N; ++j) {

            if (dist(P[i], P[j]) > 2) continue;



            point d = (P[j] - P[i]) / dist(P[i], P[j]);

            point t = (P[i] + P[j]) / 2;

            double k = sqrt(1 - sq(dist(P[i], P[j]) / 2));

            point cs[2] = {t + point(d.y, -d.x) * k, t + point(-d.y, d.x) * k};



            for (point c : cs) {

                int count = 0;

                for (int i = 0; i < N; ++i) {

                    if (dist(c, P[i]) <= 1 + EPS) ++count;

                }

                ans = max(ans, count);

            }

        }

    }



    return ans;

}



int main(void) {

    while (true) {

        cin >> N; if (N == 0) break;

        for (int i = 0; i < N; ++i) cin >> P[i].x >> P[i].y;

        cout << solve() << endl;

    }

    return 0;

}




