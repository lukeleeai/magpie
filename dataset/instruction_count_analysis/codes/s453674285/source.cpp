#include "bits/stdc++.h"

using namespace std;

typedef long double ld;

typedef complex<ld> Point;

const ld eps = 1e-9, pi = acos(-1.0);



// ??´????????????

class Line {

public:

	Point a, b;

	Line() : a(Point(0, 0)), b(Point(0, 0)) {}

	Line(Point a, Point b) : a(a), b(b) {}

	Point operator[](const int _num) {

		if (_num == 0)return a;

		else if (_num == 1)return b;

		else assert(false);

	}

};

// ????????????????????????

bool eq(ld a, ld b) {

	return (abs(a - b) < eps);

}

// ??????

ld dot(Point a, Point b) {

	return real(conj(a) * b);

}



// ??????

ld cross(Point a, Point b) {

	return imag(conj(a) * b);

}

// ????????????

class Circle {

public:

	Point p;

	ld r;

	Circle() : p(Point(0, 0)), r(0) {}

	Circle(Point p, ld r) : p(p), r(r) {}

};

// ??????????¶?

Point proj(Line l, Point p) {

	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);

	return l.a + t * (l.a - l.b);

}

// ??´?????¨???????????¢

ld dist_lp(Line l, Point p) {

	return abs(p - proj(l, p));

}

// ?????????????????????

bool isis_sp(Line s, Point p) {

	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);

}

// ?????¨??´????????????

vector<Point> is_lc(Circle c, Line l) {

	vector<Point> res;

	ld d = dist_lp(l, c.p);

	if (d < c.r + eps) {

		ld len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d); //safety;

		Point nor = (l.a - l.b) / abs(l.a - l.b);

		res.push_back(proj(l, c.p) + len * nor);

		res.push_back(proj(l, c.p) - len * nor);

	}

	return res;

}

// ?????¨??????????????¢

vector<Point> is_sc(Circle c, Line l) {

	vector<Point> v = is_lc(c, l), res;

	for (Point p : v)

		if (isis_sp(l, p)) res.push_back(p);

	return res;

}





int dx[3] = { 0,1,0 };

int dy[3] = { -1,0,1 };

// dir: ??????0, ??????1, ??????2

void kado_mituketu(int x,int y,vector<pair<int, int>>& kado, bool grid[80][80],int dir) {

	if (x >= 61) {

		kado.push_back({ x,y + 1 });

		return;

	}

	for (int i = 2; i >= 0;i--) {

		if (i == 2 && dir == 0)continue;

		if (grid[x + dx[i]][y + dy[i]] == true) {

			if (dir != i) {

				if (i != 0) {

					if (dir != 0) { kado.push_back({ x,y + 1 }); }

					else { kado.push_back({ x + 1,y + 1 }); }

				}

				else {

					if (dir == 2) { kado.push_back({ x,y + 1 }); }

					kado.push_back({ x + 1,y + 1 });

				}

				dir = i;

			}

			kado_mituketu(x + dx[i], y + dy[i], kado, grid, dir);

			return;

		}

	}

	return;

}



int main() {

	cin.tie(0);ios::sync_with_stdio(false);

	int r, n;

	while (cin >> r >> n, r | n) {

		bool grid[80][80] = { false };

		for (int i = 0; i < n;i++) {

			int xl, xr, h; cin >> xl >> xr >> h;

			for (int x = xl; x < xr;x++) {

				for (int hh = 0;hh < h;hh++) {

					grid[40 + x][40+hh] = true;

				}

			}

		}

		for (int i = 0; i <= 42;i++) grid[19 + i][39] = true;

		vector<pair<int, int>> kado;

		kado.push_back({ 20,40 });

		kado_mituketu(20,39,kado, grid, 1);

		double maxh = -1;

		for (int h = -1; h <= 22;h++) {

			if (grid[40][40 + h]) maxh = max(maxh, (double)(h + 1));

			if (grid[39][40 + h])maxh = max(maxh, (double)(h + 1));

		}

		for (int i = 0; i < kado.size();i++) {

			kado[i].first -= 40;kado[i].second -= 40;

		}

		double low = -r, up = maxh;

		for(int i = 0; i < 100;i++){

			double mid = (low + up) / 2;

			Circle cir(Point(0, mid), r);

			bool f = false;

			for (int i = 0; i < kado.size() - 1;i++) {

				Line line(Point(kado[i].first, kado[i].second), Point(kado[i + 1].first, kado[i + 1].second));

				auto pp = is_sc(cir, line);

				if (pp.size() == 0) continue;

				bool ff = false;

				for (auto p : pp) {

					if ((p.imag() - mid) > eps) {

						up = mid;

						f = true;

						ff = true;

						break;

					}

				}

				if (ff) break;

			}

			if (f) continue;

			low = mid;

		}

		cout << fixed << setprecision(6) << low + r << endl;

	}

}