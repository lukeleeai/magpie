#include <vector>

#include <iostream>

#include <utility>

#include <algorithm>

#include <string>

#include <deque>

#include <tuple>

#include <queue>

#include <functional>

#include <cmath>

#include <iomanip>

#include <map>

#include <numeric>

#include <unordered_map>

#include <unordered_set>

#include <complex>

#include <iterator>

#include <array>

//cin.sync_with_stdio(false);

//streambuf

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<double, double> pdd;

using vi = vector<int>;

using vll = vector<ll>;

using vpii = vector<pii>;

template<class T, int s>using va = vector<array<T, s>>;

template<class T, class T2> using umap = unordered_map<T, T2>;

template<class T> using uset = unordered_set<T>;

template<class T> void cmin(T &a, const T&b) { if (a > b)a = b; }

template<class T> void cmax(T &a, const T&b) { if (a < b)a = b; }

#define ALL(a) a.begin(),a.end()

#define rep(i,a) for(int i=0;i<a;i++)

#define rep1(i,a) for(int i=1;i<=a;i++)

#define rrep(i,a) for(int i=a-1;i>=0;i--)

#define rrep1(i,a) for(int i=a;i;i--)

#ifndef INT_MAX

const int INT_MAX = numeric_limits<signed>().max();

#endif

template<class T>using heap = priority_queue<T, vector<T>, greater<T>>;

template<class T>using pque = priority_queue<T, vector<T>, function<T(T, T)>>;

template <class T>

inline void hash_combine(size_t & seed, const T & v) {

	hash<T> hasher;

	seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

}

namespace std {



	template<typename S, typename T> struct hash<pair<S, T>> {

		inline size_t operator()(const pair<S, T> & v) const {

			size_t seed = 0;

			hash_combine(seed, v.first);

			hash_combine(seed, v.second);

			return seed;

		}

	};

	// Recursive template code derived from Matthieu M.

	template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>

	struct HashValueImpl

	{

		static void apply(size_t& seed, Tuple const& tuple)

		{

			HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);

			hash_combine(seed, std::get<Index>(tuple));

		}

	};



	template <class Tuple>

	struct HashValueImpl<Tuple, 0>

	{

		static void apply(size_t& seed, Tuple const& tuple)

		{

			hash_combine(seed, std::get<0>(tuple));

		}

	};



	template <typename ... TT>

	struct hash<std::tuple<TT...>>

	{

		size_t

			operator()(std::tuple<TT...> const& tt) const

		{

			size_t seed = 0;

			HashValueImpl<std::tuple<TT...> >::apply(seed, tt);

			return seed;

		}



	};

}

ll pow(ll base, ll i, ll mod) {

	ll a = 1;

	while (i) {

		if (i & 1) {

			a *= base;

			a %= mod;

		}

		base *= base;

		base %= mod;

		i /= 2;

	}

	return a;

}

class unionfind {

	vector<int> par, rank, size_;//????????§??????????????¢???????????????????????????rank???????????????size?????????

public:

	unionfind(int n) :par(n), rank(n), size_(n, 1) {

		iota(ALL(par), 0);

	}

	int find(int x) {

		if (par[x] == x)return x;

		return par[x] = find(par[x]);

	}

	void unite(int x, int y) {

		x = find(x), y = find(y);

		if (x == y)return;

		if (rank[x] < rank[y])swap(x, y);

		par[y] = x;

		size_[x] += size_[y];

		if (rank[x] == rank[y])rank[x]++;

	}

	bool same(int x, int y) {

		return find(x) == find(y);

	}

	int size(int x) {

		return size_[find(x)];

	}

};

ll gcd(ll a, ll b) {

	while (b) {

		ll c = a%b;

		a = b;

		b = c;

	}

	return a;

}

ll lcm(ll a, ll b) {

	return a / gcd(a, b)*b;

}

int popcnt(unsigned long long a) {

	a = (a & 0x5555555555555555) + (a >> 1 & 0x5555555555555555);

	a = (a & 0x3333333333333333) + (a >> 2 & 0x3333333333333333);

	a = (a & 0x0f0f0f0f0f0f0f0f) + (a >> 4 & 0x0f0f0f0f0f0f0f0f);

	a = (a & 0x00ff00ff00ff00ff) + (a >> 8 & 0x00ff00ff00ff00ff);

	a = (a & 0x0000ffff0000ffff) + (a >> 16 & 0x0000ffff0000ffff);

	return (a & 0xffffffff) + (a >> 32);

}

template<class T, class Func = function<T(T, T)>>

class segtree {

	vector<T> obj;

	int offset;

	Func updater;

	T e;

	int bufsize(int num) {

		int i = 1;

		for (; num >i; i <<= 1);

		offset = i - 1;

		return (i << 1) - 1;

	}

	T query(int a, int b, int k, int l, int r) {

		if (r <= a || b <= l)return e;

		if (a <= l && r <= b)return obj[k];

		else return updater(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));

	}

public:

	T query(int a, int b) {//[a,b)

		return query(a, b, 0, 0, offset + 1);

	}

	void updateall(int l = 0, int r = -1) {

		if (r < 0)r = offset + 1;

		l += offset, r += offset;

		do {

			l = l - 1 >> 1, r = r - 1 >> 1;

			for (int i = l; i < r; i++)obj[i] = updater(obj[i * 2 + 1], obj[i * 2 + 2]);

		} while (r);

	}

	void update(int k, T &a) {

		k += offset;

		obj[k] = a;

		while (k) {

			k = k - 1 >> 1;

			obj[k] = updater(obj[k * 2 + 1], obj[k * 2 + 2]);

		}

	}

	segtree(int n, T e, const Func &updater_ = Func()) :obj(bufsize(n), e), e(e), updater(updater_) {}

	segtree(vector<T> &vec, T e, const Func &updater = Func()) :obj(bufsize(vec.size()), e), e(e), updater(updater) {

		copy(vec.begin(), vec.end(), obj.begin() + offset);

		updateall();

	}

	typename vector<T>::reference operator[](int n) {

		return obj[n + offset];

	}

};

template<class T>

class matrix {

	vector<vector<T>> obj;

	pair<int, int> s;

public:

	matrix(pair<int, int> size, T e = 0) :matrix(size.first, size.second, e) {}

	matrix(int n, int m = -1, T e = 0) :obj(n, vector<T>(m == -1 ? n : m, e)), s(n, m == -1 ? n : m) {}

	static matrix e(int n) {

		matrix a = (n);

		for (int i = 0; i < n; i++)a[i][i] = 1;

		return a;

	}

	matrix& operator+=(const matrix &p) {

		if (s != p.s)throw runtime_error("matrix error");

		for (int i = 0; i < s.first; i++)

			for (int j = 0; j < s.second; j++)obj[i][j] += p.obj[i][j];

		return *this;

	}

	matrix operator+(const matrix &p) {

		matrix res(*this);

		return res += p;

	}

	matrix& operator-=(const matrix &p) {

		if (s != p.s)throw runtime_error("matrix error");

		for (int i = 0; i < s.first; i++)

			for (int j = 0; j < s.second; j++)obj[i][j] -= p.obj[i][j];

		return *this;

	}

	matrix operator-(const matrix &p) {

		matrix res(*this);

		return res -= p;

	}

	matrix& operator*=(T p) {

		for (auto &a : obj)

			for (auto &b : a)b *= p;

		return *this;

	}

	matrix operator*(T p) {

		matrix res(*this);

		return res *= p;

	}

	matrix operator*(const matrix &p) {

		if (s.second != p.s.first)throw runtime_error("matrix error");

		matrix ret(s.first, p.s.second);

		for (int i = 0; i < s.first; i++)

			for (int j = 0; j < s.second; j++)

				for (int k = 0; k < p.s.second; k++)ret[i][k] += obj[i][j] * p.obj[j][k];

		return ret;

	}

	matrix &operator*=(const matrix &p) {

		return *this = *this*p;

	}

	pair<int, int> size() const {

		return s;

	}

	matrix &mod(T m) {

		for (auto &a : obj)

			for (auto &b : a)b %= m;

		return *this;

	}

	typename vector<vector<T>>::reference operator[](int t) {

		return obj[t];

	}

};

template<class T> inline

matrix<T> pow(matrix<T> &base, unsigned exp) {

	auto base_(base);

	if (base_.size().first != base_.size().second)throw runtime_error("matrix error");

	matrix<T> res = matrix<T>::e(base_.size().first);

	for (;;) {

		if (exp & 1)res *= base_;

		if (!(exp /= 2))break;

		base_ *= base_;

	}

	return res;

}

template<class T> inline

matrix<T> modpow(matrix<T> &base, unsigned exp, T m) {

	auto base_(base);

	if (base.size().first != base_.size().second)throw runtime_error("matrix error");

	matrix<T> res = matrix<T>::e(base_.size().first);

	for (;;) {

		if (exp & 1)(res *= base_).mod(m);

		if (!(exp /= 2))break;

		(base_ *= base_).mod(m);

	}

	return res;

}

template<class T>int id(vector<T> &a, T b) {

	return lower_bound(ALL(a), b) - a.begin();

}

class Flow {

	int V;

	struct edge { int to, cap, rev, cost; };

	vector<vector<edge>> G;

	vector<int> level, iter, h, dist, prevv, preve;

	Flow(int size) :G(size + 1), V(size + 1) {

	}

	void add_edge(int from, int to, int cap, int cost = 0) {

		G[from].push_back(edge{ to, cap, (int)G[to].size(),cost });

		G[to].push_back(edge{ from,0,(int)G[from].size() - 1,-cost });

	}

	void bfs(int s) {

		fill(level.begin(), level.end(), -1);

		queue<int> que;

		level[s] = 0;

		que.push(s);

		while (!que.empty()) {

			int v = que.front(); que.pop();

			for (int i = 0; i < G[v].size(); i++) {

				edge &e = G[v][i];

				if (e.cap > 0 && level[e.to] < 0) {

					level[e.to] = level[v] + 1;

					que.push(e.to);

				}

			}

		}

	}

	int dfs(int v, int t, int f) {

		if (v == t)return f;

		for (int &i = iter[v]; i < G[v].size(); i++) {

			edge &e = G[v][i];

			if (e.cap > 0 && level[v] < level[e.to]) {

				int d = dfs(e.to, t, min(f, e.cap));

				if (d > 0) {

					e.cap -= d;

					G[e.to][e.rev].cap += d;

					return d;

				}

			}

		}

		return 0;

	}

	int max_flow(int s, int t) {

		level.resize(V);

		iter.resize(V);

		int flow = 0;

		for (;;) {

			bfs(s);

			if (level[t] < 0)return flow;

			fill(iter.begin(), iter.end(), 0);

			int f;

			while ((f = dfs(s, t, numeric_limits<int>::max()))>0) {

				flow += f;

			}

		}

	}

	typedef pair<int, int> P;

	int min_cost_flow(int s, int t, int f) {

		int res = 0;

		h.resize(V);

		dist.resize(V);

		prevv.resize(V);

		preve.resize(V);

		fill(h.begin(), h.end(), 0);

		while (f > 0) {

			priority_queue<P, vector<P>, greater<P>> que;

			fill(dist.begin(), dist.end(), numeric_limits<int>::max());

			dist[s] = 0;

			que.push({ 0,s });

			while (!que.empty()) {

				P p = que.top(); que.pop();

				int v = p.second;

				if (dist[v] < p.first)continue;

				for (int i = 0; i < G[v].size(); i++) {

					edge &e = G[v][i];

					if (e.cap > 0 && dist[e.to]>dist[v] + e.cost + h[v] - h[e.to]) {

						dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];

						prevv[e.to] = v;

						preve[e.to] = i;

						que.push({ dist[e.to],e.to });

					}

				}

			}

			if (dist[t] == numeric_limits<int>::max()) {

				return -1;

			}

			for (int v = 0; v < V; v++)h[v] += dist[v];



			int d = f;

			for (int v = t; v != s; v = prevv[v]) {

				d = min(d, G[prevv[v]][preve[v]].cap);

			}

			f -= d;

			res += d*h[t];

			for (int v = t; v != s; v = prevv[v]) {

				edge &e = G[prevv[v]][preve[v]];

				e.cap -= d;

				G[v][e.rev].cap += d;

			}

		}

		return res;

	}

};

const ld eps = 1e-11, pi = acos(-1.0);

typedef complex<ld> P;

typedef vector<P> VP;

ld dot(P a, P b) { return real(conj(a) * b); }

ld cross(P a, P b) { return imag(conj(a) * b); }



namespace std {

	bool operator<(const P &a, const P &b) {

		return abs(a.real() - b.real()) < eps ? a.imag() < b.imag() : a.real() < b.real();

	}

}



struct L { P a, b; };//line->l,segment->s

struct C { P p; ld r; };



int ccw(P a, P b, P c) {

	b -= a; c -= a;

	if (cross(b, c) > eps) return 1;   // counter clockwise

	if (cross(b, c) < -eps) return -1; // clockwise

	if (dot(b, c) < 0) return 2;       // c--a--b on line

	if (norm(b) < norm(c)) return -2;  // a--b--c on line

	return 0;                          // a--c--b on line

}



bool isis_ll(L l, L m) {//is intersect

	return abs(cross(l.b - l.a, m.b - m.a)) > eps;

}



bool isis_ls(L l, L s) {

	ld a = cross(l.b - l.a, s.a - l.a);

	ld b = cross(l.b - l.a, s.b - l.a);

	return (a * b < eps);

}



bool isis_lp(L l, P p) {

	return abs(cross(l.b - p, l.a - p)) < eps;

}



bool isis_ss(L s, L t) {

	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&

		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;

}



P is_ll(L s, L t) { //intersect

	P sv = s.b - s.a, tv = t.b - t.a;

	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);

}



bool isis_sp(L s, P p) {

	return abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps;

}



P proj(L l, P p) {

	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);

	return l.a + t * (l.a - l.b);

}



ld dist_lp(L l, P p) {

	return abs(p - proj(l, p));

}



ld dist_ll(L l, L m) {

	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);

}



ld dist_ls(L l, L s) {

	if (isis_ls(l, s)) return 0;

	return min(dist_lp(l, s.a), dist_lp(l, s.b));

}



ld dist_sp(L s, P p) {

	P r = proj(s, p);

	if (isis_sp(s, r)) return abs(r - p);

	return min(abs(s.a - p), abs(s.b - p));

}



ld dist_ss(L s, L t) {

	if (isis_ss(s, t)) return 0;

	ld a = min(dist_sp(s, t.a), dist_sp(t, s.a));

	ld b = min(dist_sp(s, t.b), dist_sp(t, s.b));

	return min(a, b);

}



VP is_cc(C c1, C c2) {

	VP res;

	ld d = abs(c1.p - c2.p);

	ld rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);

	ld dfr = c1.r * c1.r - rc * rc;

	if (abs(dfr) < eps) dfr = 0.0;

	else if (dfr < 0.0) return res; // no intersection

	ld rs = sqrt(dfr);

	P diff = (c2.p - c1.p) / d;

	res.push_back(c1.p + diff * P(rc, rs));

	if (dfr != 0.0) res.push_back(c1.p + diff * P(rc, -rs));

	return res;

}



bool isis_vc(vector<C> vc) {

	VP crs;

	int n = vc.size();

	rep(i, n)rep(j, i)

		for (P p : is_cc(vc[i], vc[j]))

			crs.push_back(p);

	rep(i, n)

		crs.push_back(vc[i].p);

	for (P p : crs) {

		bool valid = true;

		rep(i, n)

			if (abs(p - vc[i].p)>vc[i].r + eps)

				valid = false;

		if (valid) return true;

	}

	return false;

}



VP is_lc(C c, L l) {

	VP res;

	ld d = dist_lp(l, c.p);

	if (d < c.r + eps) {

		ld len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d); //safety;

		P nor = (l.a - l.b) / abs(l.a - l.b);

		res.push_back(proj(l, c.p) + len * nor);

		res.push_back(proj(l, c.p) - len * nor);

	}

	return res;

}



VP is_sc(C c, L l) {

	VP v = is_lc(c, l), res;

	for (P p : v)

		if (isis_sp(l, p)) res.push_back(p);

	return res;

}



vector<L> tangent_cp(C c, P p) {//????????\????

	vector<L> ret;

	P v = c.p - p;

	ld d = abs(v);

	ld l = sqrt(norm(v) - c.r * c.r);

	if (isnan(l)) { return ret; }

	P v1 = v * P(l / d, c.r / d);

	P v2 = v * P(l / d, -c.r / d);

	ret.push_back(L{ p, p + v1 });

	if (l < eps) return ret;

	ret.push_back(L{ p, p + v2 });

	return ret;

}



vector<L> tangent_cc(C c1, C c2) {

	vector<L> ret;

	if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps) {

		P center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);

		ret = tangent_cp(c1, center);

	}

	if (abs(c1.r - c2.r) > eps) {

		P out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);

		vector<L> nret = tangent_cp(c1, out);

		ret.insert(ret.end(), ALL(nret));

	}

	else {

		P v = c2.p - c1.p;

		v /= abs(v);

		P q1 = c1.p + v * P(0, 1) * c1.r;

		P q2 = c1.p + v * P(0, -1) * c1.r;

		ret.push_back(L{ q1, q1 + v });

		ret.push_back(L{ q2, q2 + v });

	}

	return ret;

}



ld area(const VP &p) {//??¢?????

	ld res = 0;

	int n = p.size();

	rep(j, n) res += cross(p[j], p[(j + 1) % n]);

	return res / 2;

}



bool is_polygon(L l, VP &g) {

	int n = g.size();

	for (int i = 0; i < n; i++) {

		P a = g[i];

		P b = g[(i + 1) % n];

		if (isis_ss(l, L{ a, b })) return true;

	}

	return false;

}



int is_in_Polygon(const VP &g, P p) {

	bool in = false;

	int n = g.size();

	for (int i = 0; i < n; i++) {

		P a = g[i] - p, b = g[(i + 1) % n] - p;

		if (imag(a) > imag(b)) swap(a, b);

		if (imag(a) <= 0 && 0 < imag(b))

			if (cross(a, b) < 0) in = !in;

		if (abs(cross(a, b)) < eps && dot(a, b) < eps) return 0; // on

	}

	if (in) return 1; // in

	return -1; // out

}



VP ConvexHull(VP ps) {

	int n = ps.size();

	int k = 0;

	sort(ps.begin(), ps.end());

	VP ch(2 * n);

	for (int i = 0; i < n; ch[k++] = ps[i++])

		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;

	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])

		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;

	ch.resize(k - 1);

	return ch;

}



VP ConvexCut(const VP &ps, L l) {

	VP Q;

	for (int i = 0; i < (int)ps.size(); i++) {

		P A = ps[i], B = ps[(i + 1) % ps.size()];

		if (ccw(l.a, l.b, A) != -1) Q.push_back(A);

		if (ccw(l.a, l.b, A) * ccw(l.a, l.b, B) < 0)

			Q.push_back(is_ll(L{ A, B }, l));

	}

	return Q;

}

double dist2(P a) {

	return real(a)*real(a) + imag(a)*imag(a);

}

int main() {

	int n;

	while (cin >> n, n) {

		vector<pdd> p(n);

		rep(i, n)cin >> p[i].first >> p[i].second;

		int m = 1;

		rep(i, n)rep(j, i) {

			if (hypot(p[i].first - p[j].first, p[i].second - p[j].second) > 2.00005)continue;

			P s = { (p[i].first + p[j].first) / 2,(p[i].second + p[j].second) / 2 };

			P t = { (p[j].second - p[i].second) / 2,(p[i].first - p[j].first) / 2 };

			t = t / abs(t)*sqrt(1 - abs(t)*abs(t));

			P c = s + t;

			int cnt = 0;

			rep(i, n)if (dist2(P{ p[i].first,p[i].second }-c) < 1.0001)cnt++;

			cmax(m, cnt);

			c = s - t;

			cnt = 0;

			rep(i, n)if (dist2(P{ p[i].first,p[i].second }-c) < 1.0001)cnt++;

			cmax(m, cnt);

		}

		cout << m << endl;

	}

}