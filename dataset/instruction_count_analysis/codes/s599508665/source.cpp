#include "stdc++.h"

#include <math.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

typedef long double ld;

typedef long long ll;



struct Point {

    ll x, y, x1 = 0, y1 = 0;

    

    Point() {}

    

    Point(ll _x, ll _y, char c) {

        x = _x;

        y = _y;

        if (c == 'U') {

            y1 = 1;

        } else if (c == 'D') {

            y1 = -1;

        } else if (c == 'R') {

            x1 = 1;

        } else {

            x1 = -1;

        }

    }

};



vector<Point> vc;



ld dist(ld t) {

    ld max_x = -1e9, max_y = -1e9, min_x = 1e9, min_y = 1e9;

    for (auto p : vc) {

        ld xx = p.x + p.x1 * t;

        ld yy = p.y + p.y1 * t;

        max_x = max(max_x, xx);

        max_y = max(max_y, yy);

        min_x = min(min_x, xx);

        min_y = min(min_y, yy);

    }

    return (max_x - min_x) * (max_y - min_y);

}



int main() {

#ifdef LOCAL

    freopen("in", "r", stdin);

    freopen("out", "w", stdout);

#endif

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.precision(20);

    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {

        ll x, y;

        char c;

        cin >> x >> y >> c;

        vc.push_back(Point(x, y, c));

    }

    ld l = 0, r = 1e11;

    for (int i = 0; i < 700; ++i) {

        ld m1 = (r - l) / 3 + l;

        ld m2 = r - (r - l) / 3;

        ld a1 = dist(m1);

        ld a2 = dist(m2);

        if (a1 > a2) {

            l = m1;

        } else {

            r = m2;

        }

    }

    cout << fixed << min(dist(l), dist(r));

    return 0;

}
