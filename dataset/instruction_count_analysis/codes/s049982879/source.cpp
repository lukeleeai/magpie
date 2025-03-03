#include <iostream>

#include <sstream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <cstring>

#include <string>

#include <vector>

#include <stack>

#include <queue>

#include <deque>

#include <map>

#include <set>

#include <bitset>

#include <numeric>

#include <utility>

#include <iomanip>

#include <algorithm>

#include <functional>

using namespace std;



typedef long long ll;

typedef vector<int> vint;

typedef vector<long long> vll;

typedef pair<int,int> pint;

typedef pair<long long, long long> pll;



#define MP make_pair

#define PB push_back

#define ALL(s) (s).begin(),(s).end()

#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl



template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P) 

{ return s << '<' << P.first << ", " << P.second << '>'; }

template<class T> ostream& operator << (ostream &s, vector<T> P) 

{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }

template<class T> ostream& operator << (ostream &s, vector<vector<T> > P) 

{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }

template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 

{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s; }









typedef double DD;



const DD INF = 1LL<<60;

const DD EPS = 1e-10;

const DD PI = acos(-1.0);

DD torad(int deg) {return (DD)(deg) * PI / 180;}

DD todeg(DD ang) {return ang * 180 / PI;}



struct Point {

    DD x, y;

    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}

    friend ostream& operator << (ostream &s, const Point &p) {return s << '(' << p.x << ", " << p.y << ')';}

};



inline Point operator + (const Point &p, const Point &q) {return Point(p.x + q.x, p.y + q.y);}

inline Point operator - (const Point &p, const Point &q) {return Point(p.x - q.x, p.y - q.y);}

inline Point operator * (const Point &p, DD a) {return Point(p.x * a, p.y * a);}

inline Point operator * (DD a, const Point &p) {return Point(a * p.x, a * p.y);}

inline Point operator * (const Point &p, const Point &q) {return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}

inline Point operator / (const Point &p, DD a) {return Point(p.x / a, p.y / a);}

inline Point conj(const Point &p) {return Point(p.x, -p.y);}

inline Point rot(const Point &p, DD ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);}

inline Point rot90(const Point &p) {return Point(-p.y, p.x);}

inline DD cross(const Point &p, const Point &q) {return p.x * q.y - p.y * q.x;}

inline DD dot(const Point &p, const Point &q) {return p.x * q.x + p.y * q.y;}

inline DD norm(const Point &p) {return dot(p, p);}

inline DD abs(const Point &p) {return sqrt(dot(p, p));}

inline DD amp(const Point &p) {DD res = atan2(p.y, p.x); if (res < 0) res += PI*2; return res;}

inline bool eq(const Point &p, const Point &q) {return abs(p - q) < EPS;}

inline bool operator < (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);}

inline bool operator > (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);}

inline Point operator / (const Point &p, const Point &q) {return p * conj(q) / norm(q);}



int ccw(const Point &a, const Point &b, const Point &c) {

    if (cross(b-a, c-a) > EPS) return 1;

    if (cross(b-a, c-a) < -EPS) return -1;

    if (dot(b-a, c-a) < -EPS) return 2;

    if (norm(b-a) < norm(c-a) - EPS) return -2;

    return 0;

}



struct Line : vector<Point> {

    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {

        this->push_back(a);

        this->push_back(b);

    }

    friend ostream& operator << (ostream &s, const Line &l) {return s << '{' << l[0] << ", " << l[1] << '}';}

};



struct Circle : Point {

    DD r;

    Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}

    friend ostream& operator << (ostream &s, const Circle &c) {return s << '(' << c.x << ", " << c.y << ", " << c.r << ')';}

};



Point proj(Point p, Line l) {

    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);

    return l[0] + (l[1] - l[0]) * t;

}

Point refl(Point p, Line l) {

    return p + (proj(p, l) - p) * 2;

}

bool isinterPL(Point p, Line l) {

    return (abs(p - proj(p, l)) < EPS);

}

bool isinterPS(Point p, Line s) {

    return (ccw(s[0], s[1], p) == 0);

}

bool isinterLL(Line l, Line m) {

    return (abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||

            abs(cross(l[1] - l[0], m[0] - l[0])) < EPS);

}

bool isinterSS(Line s, Line t) {

    if (eq(s[0], s[1])) return isinterPS(s[0], t);

    if (eq(t[0], t[1])) return isinterPS(t[0], s);

    return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 && 

            ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0);

}

DD distancePL(Point p, Line l) {

    return abs(p - proj(p, l));

}

DD distancePS(Point p, Line s) {

    Point h = proj(p, s);

    if (isinterPS(h, s)) return abs(p - h);

    return min(abs(p - s[0]), abs(p - s[1]));

}

DD distanceLL(Line l, Line m) {

    if (isinterLL(l, m)) return 0;

    else return distancePL(m[0], l);

}

DD distanceSS(Line s, Line t) {

    if (isinterSS(s, t)) return 0;

    else return min(min(distancePS(s[0], t), distancePS(s[1], t)), min(distancePS(t[0], s), distancePS(t[1], s)));

}









vector<Line> tanline(Point p, Circle c) {

    vector<Line> res;

    DD d = norm(p - c);

    DD l = d - c.r * c.r;

    if (l < -EPS) return res;

    if (l <= 0.0) l = 0.0;

    Point cq = (p - c) * (c.r * c.r / d);

    Point qs = rot90((p - c) * (-c.r * sqrt(l) / d));

    Point s1 = c + cq + qs, s2 = c + cq - qs;

    res.push_back(Line(p, s1));

    res.push_back(Line(p, s2));

    return res;

}



vector<Line> comtanline(Circle a, Circle b) {

    vector<Line> res;

    if (abs(a - b) > abs(a.r - b.r) + EPS) {

        if (abs(a.r - b.r) < EPS) {

            Point dir = b - a;

            dir = rot90(dir * (a.r / abs(dir)));

            res.push_back(Line(a + dir, b + dir));

            res.push_back(Line(a - dir, b - dir));

        }

        else {

            Point p = a * -b.r + b * a.r;

            p = p * (1.0 / (a.r - b.r));

            vector<Line> bs = tanline(p, a);

            vector<Line> as = tanline(p, b);

            for (int i = 0; i < min(as.size(), bs.size()); ++i) {

                res.push_back(Line(bs[i][1], as[i][1]));

            }

        }

    }

    if (abs(a - b) > a.r + b.r + EPS) {

        Point p = a * b.r + b * a.r;

        p = p * (1.0 / (a.r + b.r));

        vector<Line> bs = tanline(p, a);

        vector<Line> as = tanline(p, b);

        for (int i = 0; i < min(as.size(), bs.size()); ++i) {

            res.push_back(Line(bs[i][1], as[i][1]));

        }

    }

    return res;

}





inline int con(Line l, vector<Circle> vec, vector<DD> d) {

    int res = 0;

    for (int i = 0; i < vec.size(); ++i) {

        DD dis = distancePL(vec[i], l);

        if (dis >= vec[i].r - EPS && dis <= vec[i].r + d[i] + EPS) ++res;

    }

    return res;

}



int N;



int main() {

    while (cin >> N) {

        if (N == 0) break;

        

        vector<Circle> vec(N);

        vector<DD> d(N);

        for (int i = 0; i < N; ++i) {

            cin >> vec[i].x >> vec[i].y >> vec[i].r >> d[i];

        }

        

        if (N == 1 || N == 2) cout << N << endl;

        else {

            int res = 0;

            for (int i = 0; i < N; ++i) {

                for (int j = i+1; j < N; ++j) {

                    vector<Circle> I(2, vec[i]); I[1].r += d[i];

                    vector<Circle> J(2, vec[j]); J[1].r += d[j];

                    for (int p = 0; p < 2; ++p) {

                        for (int q = 0; q < 2; ++q) {

                            vector<Line> L = comtanline(I[p], J[q]);

                            for (int k = 0; k < L.size(); ++k) {

                                int tmp = con(L[k], vec, d);

                                chmax(res, tmp);

                            }

                        }

                    }

                }

            }

            cout << res << endl;

        }

    }

    return 0;

}
