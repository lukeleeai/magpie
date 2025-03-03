#include <iostream>

#include <cmath>

#include <complex>

#include <vector>

#include <set>

#include <iomanip>





using namespace std;

typedef long double ld;

typedef long long ll;

const int MAX = 60;

typedef complex<long double> Point;





namespace std {

    bool operator<(const Point &lhs, const Point &rhs) {

        return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();

    }

}



struct Circle {

    Point c;

    ld r;



    vector<Point> cross(const Circle &other) {

        vector<Point> ret;

        ld dist = abs(c - other.c);

        ld rc = (dist * dist + r * r - other.r * other.r) / (2 * dist);

        ld dfr = r * r - rc * rc;

        if (abs(dfr) < 1e-6) dfr = 0.0;

        if (dfr < 0.0) {

            return ret;

        }

        ld rs = sqrt(dfr);

        Point diff = (other.c - c) / dist;

        ret.push_back(c + diff * Point{rc, rs});

        if (dfr != 0.0) {

            ret.push_back(c + diff * Point{rc, -rs});

        }

        return ret;

    }

};



const ld eps = 1e-9;

int n, k;

Circle m[MAX + 1];

int c[MAX + 1];





int main() {



    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout << fixed << setprecision(10);

    cin >> n >> k;



    vector<Point> centers;

    for (int i = 0; i < n; ++i) {

        ld xc, yc;

        cin >> xc >> yc >> c[i];

        m[i] = {Point{xc, yc}};

        centers.push_back(m[i].c);

    }



    ld hi = 1e6;

    ld lo = 0;

    for (int ii = 0; ii < 100; ++ii) {

        ld t = lo + (hi - lo) / 2;

        vector<Point> candidate(centers);



        for (int i = 0; i < n; ++i) {

            m[i].r = (ld) t / (ld) c[i];

            for (int j = 0; j < n; ++j) {

                if (i == j) continue;

                m[j].r = (ld) t / (ld) c[j];

                auto ret = m[i].cross(m[j]);

                for (auto pt : ret) {

                    candidate.push_back(pt);

                }

            }

        }



        int mc = 0;

        for (auto pt : candidate) {

            int count = 0;

            for (int i = 0; i < n; ++i) {

                ld diff = abs(m[i].c - pt);

                if (diff < m[i].r + eps) {

                    ++count;

                }

            }

            mc = max(mc, count);

        }



        if (mc < k) {

            lo = t + eps;

        } else {

            hi = t;

        }

    }



    cout << lo;



    return 0;

}
