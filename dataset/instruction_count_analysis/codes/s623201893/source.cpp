#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable: 4244) // 最悪をします

#include <iostream>

#include <cmath>

#include <algorithm>

#include <vector>

#include <numeric>

#include <queue>

#include <stack>

#include <map> 

#include <set>

#include <string>

#include <functional>

#include <list>

#include <random>

#include <time.h>

#include <iomanip>

#include <assert.h>

#include <numeric>

#include <sstream>

#define BIT(nr) (1UL << (nr))

#define int long long

//#define ll long long

#define double long double

#define mod 1000000007

#define MAXN (int)1e+5 * 2+1

#define LL_MAX 9223372036854775807	//ない環境用

#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用

#define MIN -(9223372036854775807 / 2)

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)

#define rep(i,n) REP(i,0,n)

#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

#define ALLOF(c) (c).begin(), (c).end()

#define REPS(i,x) for(int i=1;i<=(int)(x);i++)

#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)

#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

#define mp make_pair

template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }





using namespace std;



//デバッグ用カッコの有無

#ifdef DEBUG

template <class T>ostream &operator<<(ostream &o, const vector<T>&v)

{

	o << "{"; for (int i = 0; i<(int)v.size(); i++)o << (i>0 ? ", " : "") << v[i]; o << "}"; return o;

}

#endif // DEBUG



template <class T>ostream &operator<<(ostream &o, const vector<T>&v)

{

	for (int i = 0; i<(int)v.size(); i++)o << (i>0 ? " " : "") << v[i]; return o;

}



int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位

int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位



int dxp[4] = { 0, 1 }; // x軸方向への変位(正のみ)

int dyp[4] = { 1, 0 }; // y軸方向への変位(負のみ)



using Weight = int;

using Flow = int;

struct Edge {

	int src, dst;



	// libalgo のものに追加、メンバを追加するだけなので互換性は崩さないはず、逆辺のG[e.dstの]インデックスを保持

	int rev;

	Weight weight;

	Flow cap;

	Edge() : src(0), dst(0), weight(0) {}

	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}

};

using Edges = std::vector<Edge>;

using Graph = std::vector<Edges>;

using Array = std::vector<Weight>;

using Matrix = std::vector<Array>;



void add_edge(Graph& g, int a, int b, Weight w = 1) {

	g[a].emplace_back(a, b, w);

	g[b].emplace_back(b, a, w);

}

void add_arc(Graph& g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }



// 辺がメンバに src と dst を持つ隣接リスト表記のグラフをダンプ(https://hello-world-494ec.firebaseapp.com/) に投げることを想定

template <typename T>

void dump_graph(T G) {

	int V = G.size();

	int E = 0;

	ostringstream os;



	for (auto es : G) {

		for (auto e : es) {

			E++;

			os << e.src << " " << e.dst << "\n";

		}

	}

	cout << V << " " << E << "\n";

	cout << os.str() << "\n";

}



// グリッドからグラフを構築

// @pre: gはノード数H*Wのグラフ

void create_from_grid(Graph& g, int h, int w, vector<string>& mapData, char wall) {

	//グラフ構築 O(HW)

	rep(y, h) {

		rep(x, w) {

			if (mapData[y][x] == wall) {

				continue;

			}



			int id = y * w + x;

			//右と下(変位が正)のみ見る(辺の重複を回避するため)

			rep(i, 2) {

				int nx = x + dxp[i];

				int ny = y + dyp[i];

				int nid = ny * w + nx;

				if (nx < 0 || nx >= w) {

					continue;

				}

				if (ny < 0 || ny >= h) {

					continue;

				}

				if (mapData[ny][nx] != wall) {

					add_edge(g, id, nid);

				}

			}

		}

	}

}



// マスに重みが定義されるグリッドから重み付きグラフを構築、ダイクストラなどをするとき始点のこすとは入らないことに注意

// @pre: gはノード数H*Wのグラフ

void create_weighted_from_grid(Graph& g, int h, int w, vector<vector<int>>& mapData) {

	//グラフ構築 O(HW)

	rep(y, h) {

		rep(x, w) {

			int id = y * w + x;

			// こんどは全方向見る(行きと帰りで重みが違うはず)

			rep(i, 4) {

				int nx = x + dx[i];

				int ny = y + dy[i];

				int nid = ny * w + nx;

				if (nx < 0 || nx >= w) {

					continue;

				}

				if (ny < 0 || ny >= h) {

					continue;

				}



				// 移動先のコストを足す

				add_arc(g, id, nid, mapData[ny][nx]);

			}

		}

	}

}



// グリッドにおいて座標をグラフのノード番号に変換する

int point_to_node_num(int x, int y, int W) {

	return y * W + x;

}



struct uf_tree {

	std::vector<int> parent;

	int __size;

	uf_tree(int size_) : parent(size_, -1), __size(size_) {}

	void unite(int x, int y) {

		if ((x = find(x)) != (y = find(y))) {

			if (parent[y] < parent[x]) std::swap(x, y);

			parent[x] += parent[y];

			parent[y] = x;

			__size--;

		}

	}

	bool is_same(int x, int y) { return find(x) == find(y); }

	int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }

	int size(int x) { return -parent[find(x)]; }

	int size() { return __size; }

};







//!!!問題をちゃんと読む!!!

//!!!問題をちゃんと読め!!!

//!!!問題は読みましたか？!!!



template <signed M, unsigned T>

struct mod_int {

	constexpr static signed MODULO = M;

	constexpr static unsigned TABLE_SIZE = T;



	signed x;



	mod_int() : x(0) {}



	mod_int(long long y) : x(static_cast<signed>(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO)) {}



	mod_int(signed y) : x(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO) {}



	mod_int& operator+=(const mod_int& rhs) {

		if ((x += rhs.x) >= MODULO) x -= MODULO;

		return *this;

	}



	mod_int& operator-=(const mod_int& rhs) {

		if ((x += MODULO - rhs.x) >= MODULO) x -= MODULO;

		return *this;

	}



	mod_int& operator*=(const mod_int& rhs) {

		x = static_cast<signed>(1LL * x * rhs.x % MODULO);

		return *this;

	}



	mod_int& operator/=(const mod_int& rhs) {

		x = static_cast<signed>((1LL * x * rhs.inv().x) % MODULO);

		return *this;

	}



	mod_int operator-() const { return mod_int(-x); }



	mod_int operator+(const mod_int& rhs) const { return mod_int(*this) += rhs; }



	mod_int operator-(const mod_int& rhs) const { return mod_int(*this) -= rhs; }



	mod_int operator*(const mod_int& rhs) const { return mod_int(*this) *= rhs; }



	mod_int operator/(const mod_int& rhs) const { return mod_int(*this) /= rhs; }



	bool operator<(const mod_int& rhs) const { return x < rhs.x; }



	mod_int inv() const {

		assert(x != 0);

		if (x <= static_cast<signed>(TABLE_SIZE)) {

			if (_inv[1].x == 0) prepare();

			return _inv[x];

		}

		else {

			signed a = x, b = MODULO, u = 1, v = 0, t;

			while (b) {

				t = a / b;

				a -= t * b;

				std::swap(a, b);

				u -= t * v;

				std::swap(u, v);

			}

			return mod_int(u);

		}

	}



	mod_int pow(long long t) const {

		assert(!(x == 0 && t == 0));

		mod_int e = *this, res = mod_int(1);

		for (; t; e *= e, t >>= 1)

			if (t & 1) res *= e;

		return res;

	}



	mod_int fact() {

		if (_fact[0].x == 0) prepare();

		return _fact[x];

	}



	mod_int inv_fact() {

		if (_fact[0].x == 0) prepare();

		return _inv_fact[x];

	}



	mod_int choose(mod_int y) {

		assert(y.x <= x);

		return this->fact() * y.inv_fact() * mod_int(x - y.x).inv_fact();

	}



	static mod_int _inv[TABLE_SIZE + 1];



	static mod_int _fact[TABLE_SIZE + 1];



	static mod_int _inv_fact[TABLE_SIZE + 1];



	static void prepare() {

		_inv[1] = 1;

		for (int i = 2; i <= (int)TABLE_SIZE; ++i) {

			_inv[i] = 1LL * _inv[MODULO % i].x * (MODULO - MODULO / i) % MODULO;

		}

		_fact[0] = 1;

		for (unsigned i = 1; i <= TABLE_SIZE; ++i) {

			_fact[i] = _fact[i - 1] * signed(i);

		}

		_inv_fact[TABLE_SIZE] = _fact[TABLE_SIZE].inv();

		for (int i = (int)TABLE_SIZE - 1; i >= 0; --i) {

			_inv_fact[i] = _inv_fact[i + 1] * (i + 1);

		}

	}

};



template <signed M, unsigned F>

std::ostream& operator<<(std::ostream& os, const mod_int<M, F>& rhs) {

	return os << rhs.x;

}



template <signed M, unsigned F>

std::istream& operator >> (std::istream& is, mod_int<M, F>& rhs) {

	long long s;

	is >> s;

	rhs = mod_int<M, F>(s);

	return is;

}



template <signed M, unsigned F>

mod_int<M, F> mod_int<M, F>::_inv[TABLE_SIZE + 1];



template <signed M, unsigned F>

mod_int<M, F> mod_int<M, F>::_fact[TABLE_SIZE + 1];



template <signed M, unsigned F>

mod_int<M, F> mod_int<M, F>::_inv_fact[TABLE_SIZE + 1];



template <signed M, unsigned F>

bool operator==(const mod_int<M, F>& lhs, const mod_int<M, F>& rhs) {

	return lhs.x == rhs.x;

}



template <int M, unsigned F>

bool operator!=(const mod_int<M, F>& lhs, const mod_int<M, F>& rhs) {

	return !(lhs == rhs);

}



const signed MF = 1000010;

const signed MOD = 1000000007;



using mint = mod_int<MOD, MF>;



mint binom(int n, int r) { return (r < 0 || r > n || n < 0) ? 0 : mint(n).choose(r); }



mint fact(int n) { return mint(n).fact(); }



mint inv_fact(int n) { return mint(n).inv_fact(); }



//出典 http://beet-aizu.hatenablog.com/entry/2017/12/01/225955

/*

コンストラクタ引数説明

int n_

要素数。

f

2つの要素Tをマージするための関数。

区間MAX区間更新の時: max

区間Sum区間Addの時: +

g

1つの要素Tに作用素Eを適用するための関数。

区間MAX区間更新の時: =

区間Sum区間Addの時: +

h

2つの作用素Eをマージするための関数。

区間MAX区間更新の時: =

区間Sum区間Addの時: +

T d1

演算fの単位元。

区間MAX区間更新の時: -INF　

区間Sum区間Addの時: 0

E d0,

g, hの単位元。

区間MAX区間更新の時: 定義域外のどこか

区間Sum区間Addの時: 0

vector<T> v = vector<T>()

セグ木を構成するときのvector

P p = [](E a, int b) {return a; }

区間の長さbを引数に取り、区間の長さによって変化する作用素E'を返す関数。

例えば、区間MAX区間Addの時なんかは区間長によって足すべき数が変化するので必要

区間Sum区間Addの時: *



//具体例

//区間chmin, 区間min

auto myMin = [](int a, int b) {return min(a, b); };

SegmentTree<int, int> seg(n, myMin, myMin, myMin, LL_HALFMAX, LL_HALFMAX);

//区間update、区間min

SegmentTree<int, int> seg(n, myMin, myMin, myMin, LL_HALFMAX, LL_HALFMAX);

//区間Add、区間Sum

vector<int> v(0, N + 1);

SegmentTree<int, int> segtree(N + 1, plus<int>(), plus<int>(), plus<int>(), 0, 0, v, [](int a, int b) {return a * b; });

//区間Add、区間Min

vector<int> v(0, N + 1);

SegmentTree<int, int> segtree(N + 1, myMin, plus<int>(), plus<int>(), LL_HALFMAX, 0, v, [](int a, int b) {return a; });

*/



template <typename T, typename E>

struct SegmentTree {

	typedef function<T(T, T)> F;

	typedef function<T(T, E)> G;

	typedef function<E(E, E)> H;

	typedef function<E(E, int)> P;

	int n;

	F f;

	G g;

	H h;

	P p;

	T d1;

	E d0;

	vector<T> dat;

	vector<E> laz;

	SegmentTree(int n_, F f, G g, H h, T d1, E d0,

		vector<T> v = vector<T>(), P p = [](E a, int b) {return a; }) :

		f(f), g(g), h(h), d1(d1), d0(d0), p(p) {

		init(n_);

		if (n_ == (int)v.size()) build(n_, v);

	}

	//初期化。要素配列と遅延配列を2*n-1個にする

	void init(int n_) {

		n = 1;

		while (n < n_) n *= 2;

		dat.clear();

		dat.resize(2 * n - 1, d1);

		laz.clear();

		laz.resize(2 * n - 1, d0);

	}

	//既存のvectorからセグ木を構築

	void build(int n_, vector<T> v) {

		for (int i = 0; i < n_; i++) dat[i + n - 1] = v[i];

		for (int i = n - 2; i >= 0; i--)

			dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);

	}

	//ノードを評価する。

	inline void eval(int len, int k) {

		//遅延配列に単位元が入ってたら評価済みなのでおしまい

		if (laz[k] == d0) return;

		//葉ノードでないなら遅延伝播する

		if (k * 2 + 1 < n * 2 - 1) {

			//h: 2つの作用素を引数に取り合成した作用素を返す関数

			laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);

			laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);

		}

		//p: このノードに対応する区間長と作用素を引数に取り、区間長に対応する作用素を返す関数

		//dat[k] にlaz に溜めていた作用素を適用(g: 要素型と作用素型を引数に取り、要素に作用素を作用させた結果を返す関数、ここでの作用素とは区間Sum区間Addなら (+ 3) とか)

		dat[k] = g(dat[k], p(laz[k], len));

		//適用し終わったので遅延配列をクリア

		laz[k] = d0;

	}

	//[l,r)の区間を再帰的に見ながら0-indexedの[a, b)を更新する

	T update(int a, int b, E x, int k, int l, int r) {

		//先に評価

		eval(r - l, k);

		//範囲外ならなにもしないでそのノードが持つ値を返す

		if (r <= a || b <= l) return dat[k];

		//完全被覆なら既に遅延配列に入っている作用素と追加したい作用素をマージした後にそれを要素に作用させた結果を返す、pは区間長に対応する作用素を得るための（ｒｙ

		if (a <= l && r <= b) {

			laz[k] = h(laz[k], x);

			return g(dat[k], p(laz[k], r - l));

		}

		//完全被覆でも範囲外でもないなら(中途半端にかぶっているなら)完全被覆と範囲外の境界が見えるまで木を潜って変化後の値を得る

		return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),

			update(a, b, x, k * 2 + 2, (l + r) / 2, r));

	}

	T update(int a, int b, E x) {

		return update(a, b, x, 0, 0, n);

	}



	T update(int a, E x) {

		return update(a, a + 1, x);

	}



	T query(int a, int b, int k, int l, int r) {

		eval(r - l, k);

		//範囲外なら単位元を返す

		if (r <= a || b <= l) return d1;

		//完全被覆ならそのまま返す

		if (a <= l && r <= b) return dat[k];

		//一部被覆なら完全被覆と範囲外に分かれるまで木を潜る

		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);

		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

		return f(vl, vr);

	}

	//0-indexedで[a, b)の区間*を求める

	T query(int a, int b) {

		return query(a, b, 0, 0, n);

	}



	T query(int a) {

		return query(a, a + 1, 0, 0, n);

	}



	void debug_print(int num) {

		vector<T> v;

		rep(i, num) {

			v.push_back(query(i));

		}

		cout << "{" << v << "}\n";

	}

};



//座標圧縮



class compress {

public:

	map<int, int> zip;

	vector<int> unzip;



	compress(vector<int> x)

	{

		sort(x.begin(), x.end());

		x.erase(unique(x.begin(), x.end()), x.end());

		for (int i = 0; i < x.size(); i++) {

			zip[x[i]] = i;

			unzip.push_back(i);

		}

	}

};





int euclidean_gcd(int a, int b) {

	while (1) {

		if (a < b) swap(a, b);

		if (!b) break;

		a %= b;

	}

	return a;

}



//https://ei1333.github.io/luzhiled/snippets/dp/cumulative-sum-2d.html

template< class T >

struct CumulativeSum2D {

	vector< vector< T > > data;



	CumulativeSum2D(int W, int H) : data(W + 1, vector< int >(H + 1, 0)) {}



	void add(int x, int y, T z) {

		++x, ++y;

		if (x >= data.size() || y >= data[0].size()) return;

		data[x][y] += z;

	}



	void build() {

		for (int i = 1; i < data.size(); i++) {

			for (int j = 1; j < data[i].size(); j++) {

				data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];

			}

		}

	}



	T query(int sx, int sy, int gx, int gy) {

		return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);

	}

};



//lib

int nC2(int n) {

	return n * (n - 1) / 2;

}



class node {

public:

	int depth;

	int num;



	node(int d, int n) {

		depth = d;

		num = n;

	}

};



template< class T >

struct CumulativeSum {

	vector< T > data;



	CumulativeSum(int sz) : data(sz, 0) {};



	void add(int k, T x) {

		data[k] += x;

	}



	void build() {

		for (int i = 1; i < data.size(); i++) {

			data[i] += data[i - 1];

		}

	}



	T query(int k) {

		if (k < 0) return (0);

		return (data[min(k, (int)data.size() - 1)]);

	}

	//[left, right]の和

	T query(int left, int right) {

		return query(right) - query(left - 1);

	}

};



std::vector<int> eratosthenes_sieve(int n) {

	std::vector<int> ps(n + 1);

	std::iota(ps.begin() + 2, ps.end(), 2);

	for (int i = 2; i * i <= n; ++i)

		if (ps[i])

			for (int j = i * i; j <= n; j += i) ps[j] = 0;

	return ps;

}



std::vector<int> make_primes(int n) {

	std::vector<int> ps = eratosthenes_sieve(n);

	ps.erase(std::remove(ps.begin(), ps.end(), 0), ps.end());

	return ps;

}



// 区間[a, b)の素数判定をする、is_prime[i]: a + i が素数 or not つまり is_prime[i-a] が true: iが素数

std::vector<bool> segment_eratosthenes_sieve(int a, int b) {

	vector<bool> is_prime(b - a, true);

	vector<bool> is_prime_small;

	for (int i = 0; i*i < b; i++)is_prime_small.push_back(true);



	for (int i = 2; i*i < b; i++) {

		if (is_prime_small[i]) {

			for (int j = 2 * i; j*j < b; j += i) {

				is_prime_small[j] = false;	// [2, sqrt(b))のふるい

			}

			// (a + i - 1LL) / i * i a以上の最小のiの倍数

			for (int j = max(2LL, (a + i - 1LL) / i) * i; j < b; j += i) {

				is_prime[j - a] = false;	// [a, b)のふるい

			}

		}

	}

	return is_prime;

}



vector< int64_t > divisor(int64_t n) {

	vector< int64_t > ret;

	for (int64_t i = 1; i * i <= n; i++) {

		if (n % i == 0) {

			ret.push_back(i);

			if (i * i != n) ret.push_back(n / i);

		}

	}

	sort(begin(ret), end(ret));

	return (ret);

}









// 汎用的な二分探索のテンプレ(めぐる式)

int binary_search(function<bool(int)> isOk, int ng, int ok) {



	/* ok と ng のどちらが大きいかわからないことを考慮 */

	while (abs(ok - ng) > 1) {

		int mid = (ok + ng) / 2;



		if (isOk(mid)) ok = mid;

		else ng = mid;

	}

	return ok;

}



std::pair<std::vector<Weight>, bool> bellmanFord(const Graph& g, int s) {

	int n = g.size();

	const Weight inf = std::numeric_limits<Weight>::max() / 8;

	Edges es;

	for (int i = 0; i < n; i++)

		for (auto& e : g[i]) es.emplace_back(e);



	//初期化、スタート地点以外の距離は無限大

	std::vector<Weight> dist(n, inf);

	dist[s] = 0;

	bool negCycle = false;

	for (int i = 0;; i++) {

		bool update = false;

		//すべての辺について、その辺をとおった場合に最短経路が更新できる場合は更新する

		for (auto& e : es) {

			if (dist[e.src] != inf && dist[e.dst] > dist[e.src] + e.weight) {

				dist[e.dst] = dist[e.src] + e.weight;

				update = true;

			}

		}

		//更新がなくなったらおはり

		if (!update) break;

		//n回以上更新されてたら負閉路がある

		if (i > n) {

			negCycle = true;

			break;

		}

	}

	return std::make_pair(dist, !negCycle);

}



//ゴールを指定して、それまでのパスに負閉路がなかったらOK(嘘修正済)

std::pair<std::vector<Weight>, bool> bellmanFord(const Graph& g, int s, int d) {

	int n = g.size();

	const Weight inf = std::numeric_limits<Weight>::max() / 8;

	Edges es;

	for (int i = 0; i < n; i++)

		for (auto& e : g[i]) es.emplace_back(e);



	//初期化、スタート地点以外の距離は無限大

	std::vector<Weight> dist(n, inf);

	dist[s] = 0;

	bool negCycle = false;

	for (int i = 0; i < n * 2; i++) {

		bool update = false;

		//すべての辺について、その辺をとおった場合に最短経路が更新できる場合は更新する

		for (auto& e : es) {

			if (dist[e.src] != inf && dist[e.dst] > dist[e.src] + e.weight) {

				// n回目の更新で d が更新されてたら問答無用で負閉路ありとしてNG

				if (i >= n - 1 && e.dst == d) {

					negCycle = true;

				}

				// 終点以外に負閉路がある場合はそこの距離を十分小さい値に置き換える

				else if (i >= n - 1) {

					dist[e.dst] = -inf;

					update = true;

				}

				else {

					dist[e.dst] = dist[e.src] + e.weight;

					update = true;

				}

			}

		}

		//更新がなくなったらおはり

		if (!update) break;

	}

	return std::make_pair(dist, !negCycle);

}



//R[i] == S[i] を中心とした極大回文長 なるvector Rを返す

vector<int> Manachar(string S) {

	int len = S.length();

	vector<int> R(len);



	int i = 0, j = 0;

	while (i < S.size()) {

		while (i - j >= 0 && i + j < S.size() && S[i - j] == S[i + j]) ++j;

		R[i] = j;

		int k = 1;

		while (i - k >= 0 && i + k < S.size() && k + R[i - k] < j) R[i + k] = R[i - k], ++k;

		i += k; j -= k;

	}

	return R;

}



std::vector<int> tsort(const Graph &g) {

	int n = g.size(), k = 0;

	std::vector<int> ord(n), in(n);

	for (auto &es : g)

		for (auto &e : es) in[e.dst]++;

	std::queue<int> q;

	//入次数0の点をキューに追加

	for (int i = 0; i < n; ++i)

		if (in[i] == 0) q.push(i);

	while (q.size()) {

		int v = q.front();

		//Sから node n を削除する

		q.pop();

		//L に n を追加する

		ord[k++] = v;

		for (auto &e : g[v]) {

			//選択した点から出てる辺を削除、0になったらキューに追加

			if (--in[e.dst] == 0) {

				q.push(e.dst);

			}

		}



	}

	return *std::max_element(in.begin(), in.end()) == 0 ? ord : std::vector<int>();

}



std::vector<Weight> dijkstra(const Graph &g, int s) {

	const Weight INF = std::numeric_limits<Weight>::max() / 8;

	using state = std::tuple<Weight, int>;

	std::priority_queue<state> q;

	std::vector<Weight> dist(g.size(), INF);

	dist[s] = 0;

	q.emplace(0, s);

	while (q.size()) {

		Weight d;

		int v;

		std::tie(d, v) = q.top();

		q.pop();

		d *= -1;

		/* if(v == t) return d; */

		if (dist[v] < d) continue;

		for (auto &e : g[v]) {

			if (dist[e.dst] > dist[v] + e.weight) {

				dist[e.dst] = dist[v] + e.weight;

				q.emplace(-dist[e.dst], e.dst);

			}

		}

	}

	return dist;

}



Matrix WarshallFloyd(const Graph &g) {

	auto const INF = std::numeric_limits<Weight>::max() / 8;

	int n = g.size();

	Matrix d(n, Array(n, INF));

	rep(i, n) d[i][i] = 0;

	rep(i, n) for (auto &e : g[i]) d[e.src][e.dst] = std::min(d[e.src][e.dst], e.weight);

	rep(k, n) rep(i, n) rep(j, n) {

		if (d[i][k] != INF && d[k][j] != INF) d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);

	}

	return d;

}



std::pair<std::vector<int>, std::vector<int>> prime_factor_decomp(int n) {

	std::vector<int> p, e;

	int m = n;

	for (int i = 2; i * i <= n; i++) {

		if (m % i != 0) continue;

		int c = 0;

		while (m % i == 0) c++, m /= i;

		p.push_back(i);

		e.push_back(c);

	}

	if (m > 1) {

		p.push_back(m);

		e.push_back(1);

	}

	return std::make_pair(p, e);

}



int extgcd(int a, int b, int &x, int &y) {

	int g = a;

	x = 1;

	y = 0;

	if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;

	return g;

}



// 不定方程式 ax + by = c の一般整数解(pt + q, rt + s)を求める

/*

* exist: 解が存在するか否か

* p, q, r, s: 存在するならば不定方程式の一般解(pt + q, rt + s)

* ここで、式変形から、p > 0、 q < 0 となることに注意する。(解の条件を絞るときなどに必要になる)

*/

void IndeterminateEq(int a, int b, int c, bool& exist, int& p, int& q, int& r, int& s) {

	int X, Y;



	int g = euclidean_gcd(a, b);



	// c が最大公約数の整数倍でないならNG

	if (c % g != 0) {

		exist = false;

		return;

	}

	exist = true;



	// 拡張ユークリッドの互除法で ax + by = gcd(a, b) なる (X, Y) を求める

	extgcd(a, b, X, Y);

	int m = c / g;



	// ax + by = c の解にする

	X *= m;

	Y *= m;



	int a2 = a / g;

	int b2 = b / g;



	p = b2;

	q = X;

	r = -a2;

	s = Y;

}



// x^n mod modulo を繰り返し二乗法で計算する 

// n を 2^k の和で表す -> n を二進表記したとき、kbit目(0-indexed)が立っているときだけx^kをかける

int mod_pow(int x, int n, int modulo) {

	int res = 1;

	while (n > 0) {

		if (n & 1) {

			res = res * x % modulo;

		}

		x = x * x % modulo;

		n >>= 1;

	}

	return res;

}



int64_t popcnt(int64_t n)

{

	int64_t c = 0;

	c = (n & 0x5555555555555555) + ((n >> 1) & 0x5555555555555555);

	c = (c & 0x3333333333333333) + ((c >> 2) & 0x3333333333333333);

	c = (c & 0x0f0f0f0f0f0f0f0f) + ((c >> 4) & 0x0f0f0f0f0f0f0f0f);

	c = (c & 0x00ff00ff00ff00ff) + ((c >> 8) & 0x00ff00ff00ff00ff);

	c = (c & 0x0000ffff0000ffff) + ((c >> 16) & 0x0000ffff0000ffff);

	c = (c & 0x00000000ffffffff) + ((c >> 32) & 0x00000000ffffffff);

	return(c);

}



/*

行列積と行列累乗

行列積

vector<vector<T>> matrixMultiplies(vector<vector<T>> l, vector<vector<T>> r, F plus = plus<T>(), G multiple = multiplies<T>(), T eplus = 0LL)

行列累乗

vector<vector<T>> matrixPower(vector<vector<T>> m, int n, F plus = std::plus<T>(), G multiple = multiplies<T>(), T eplus = 0LL, T emultiple = 1LL)

T:			考える集合(競プロにおいてはたぶんほぼ整数)

l:			左からかける行列

r:			右からかける行列

plus:		加法演算

multiple:	乗法演算

eplus:		加法の単位元

emultiple:	乗法の単位元

*/

template<typename T = long long, typename F = decltype(std::plus<T>()), typename G = decltype(multiplies<T>())>

vector<vector<T>> matrixMultiplies(vector<vector<T>> l, vector<vector<T>> r, F plus = plus<T>(), G multiple = multiplies<T>(), T eplus = 0LL) {

	int rx = r[0].size();

	int ry = r.size();

	vector<vector<T> > ret;



	for (int y = 0; y < ry; y++) {

		vector<T> add;

		for (int x = 0; x < rx; x++) {

			T cell = eplus;

			for (int i = 0; i < ry; i++) {

				T mul = multiple(l[y][i], r[i][x]);

				cell = plus(cell, mul);

			}

			add.push_back(cell);

		}

		ret.push_back(add);

	}

	return ret;

}



template<typename T = long long, typename F = decltype(std::plus<T>()), typename G = decltype(multiplies<T>())>

vector<vector<T>> matrixPower(vector<vector<T>> m, int n, F plus = std::plus<T>(), G multiple = multiplies<T>(), T eplus = 0LL, T emultiple = 1LL) {

	int k = m.size();

	if (n == 0) {

		vector<vector<T> > E;

		for (int i = 0; i < k; i++) {

			// 単位行列は対角成分を乗法単位元、非対角成分をゼロ元で埋める

			vector<T> v(k, eplus);

			v[i] = emultiple;

			E.push_back(v);

		}

		return E;

	}

	vector<vector<T>> ret = matrixPower(matrixMultiplies(m, m, plus, multiple, eplus), n / 2, plus, multiple, eplus, emultiple);

	if (n % 2 == 1) {

		ret = matrixMultiplies(m, ret, plus, multiple);

	}

	return ret;

}



// フロー系のアルゴリズム

// 最大流

/*

Ford-Fulkerson法(蟻本) O(F|E|)

F: 最大流量

E: 辺数

コンストラクタ引数でノード数nを受け取り初期化し、add_edge で辺と逆辺を追加していく

*/

class Ford_Fulkerson {

private:

	struct Edge {

		int src, dst;



		// libalgo のものに追加、メンバを追加するだけなので互換性は崩さないはず、逆辺のG[e.dstの]インデックスを保持

		int rev;

		int cap;

		Edge(int s, int d, int c, int r) : src(s), dst(d), cap(c), rev(r) {}

	};

	vector<vector<Edge> > G;

	vector<bool> used;

public:

	Ford_Fulkerson(int n) :

		G(n),

		used(n, false)

	{}



	void add_edge(int s, int d, int cap) {

		G[s].emplace_back(s, d, cap, G[d].size());

		G[d].emplace_back(d, s, 0, G[s].size() - 1);

	}



	int dfs(int v, int t, int f) {

		if (v == t) {

			return f;

		}

		used[v] = true;

		for (Edge& e : G[v]) {

			if (!used[e.dst] && e.cap > 0) {

				// 流せる辺があったら流す

				int d = dfs(e.dst, t, min(f, e.cap));

				if (d > 0) {

					// 辺の残り容量を減らす

					e.cap -= d;

					// 逆辺の容量を増やす

					G[e.dst][e.rev].cap += d;

					return d;

				}

			}

		}

		// t にたどり着けなかったら0

		return 0;

	}

	int max_flow(int s, int t) {

		int flow = 0;



		while (1) {

			for (int i = 0; i < used.size(); i++) {

				used[i] = false;

			}

			int f = dfs(s, t, LL_HALFMAX);

			if (f == 0) {

				return flow;

			}

			flow += f;

		}

	}



};



/*

Dinic法 From libalgo O(V^2 * E)

dinic::solve(s, t) : s -> t の最大流を求める

dinic;;flow[u][v] : 辺(u, v)の流量

*/

struct dinic {

	int n, s, t;

	std::vector<int> level, prog, que;

	std::vector<std::vector<Flow>> cap, flow;

	std::vector<std::vector<int>> g;

	Flow inf;

	dinic(const Graph &graph)

		: n(graph.size()),

		cap(n, std::vector<Flow>(n)),

		flow(n, std::vector<Flow>(n)),

		g(n, std::vector<int>()),

		inf(std::numeric_limits<Flow>::max() / 8) {

		for (int i = 0; i < n; i++) {

			for (auto &e : graph[i]) {

				int u = e.src, v = e.dst;

				Flow c = e.cap;

				cap[u][v] += c;

				cap[v][u] += c;

				flow[v][u] += c;

				g[u].push_back(v);

				g[v].push_back(u);

			}

		}

	}

	// 残りを求める

	inline Flow residue(int u, int v) { return cap[u][v] - flow[u][v]; }



	// 実際に最大流問題を解く

	Flow solve(int s_, int t_) {

		this->t = t_, this->s = s_;

		que.resize(n + 1);

		Flow res = 0;

		// levelize() == false: bfs で s から t に到達できなかった

		while (levelize()) {

			prog.assign(n, 0);

			res += augment(s, inf);

		}

		return res;

	}

	// bfs でレベルグラフをつくる

	bool levelize() {

		int l = 0, r = 0;

		level.assign(n, -1);

		level[s] = 0;

		que[r++] = s;

		while (l != r) {

			int v = que[l++];

			if (v == t) break;

			for (const int &d : g[v]) {

				// まだレベルが決まっておらず、v -> dの辺に流せるならlevel[d] = level[v] + 1

				if (level[d] == -1 && residue(v, d) != 0) {

					level[d] = level[v] + 1;

					que[r++] = d;

				}

			}

		}

		// t に到達できるなら true を返す

		return level[t] != -1;

	}

	// dfs で実際に流してみる

	Flow augment(int v, Flow lim) {

		Flow res = 0;

		if (v == t) return lim;

		// prog[v]: dfs において、vを展開する際、vの子の何番目まで展開したかを覚えておく

		for (int &i = prog[v]; i < (int)g[v].size(); i++) {

			const int &d = g[v][i];

			// v -> d に流せない or v(流す側) の方がレベルが大きい(=深い)場合NG

			if (residue(v, d) == 0 || level[v] >= level[d]) continue;

			// 流せるなら、流せるだけ流す

			const Flow aug = augment(d, std::min(lim, residue(v, d)));

			flow[v][d] += aug;

			flow[d][v] -= aug;

			res += aug;

			lim -= aug;

			// ノードvに来ている流量を使い切ったら終わり

			if (lim == 0) break;

		}

		return res;

	}

};



/*

Primal-Dual法(蟻本版 / ベルマンフォード)

*/



class Primal_Dual_BellmanFord {

	using Cost = int;

	struct Edge {

		int src, dst;



		// libalgo のものに追加、メンバを追加するだけなので互換性は崩さないはず、逆辺のG[e.dstの]インデックスを保持

		int rev;

		Cost cost;

		Flow cap;

		Edge(int s, int d, int aRev, Cost aCost, Flow aCap) : src(s), dst(d), rev(aRev), cost(aCost), cap(aCap) {}

	};



	int V;							//頂点数

	vector<vector<Edge>> G;			// 隣接リスト

	vector<int> dist;				// 最短距離

	vector<int> prevv;				// 直前の頂点

	vector<int> preve;				// 直前の辺

	const int INF;



public:

	// 頂点数 n を引数にとって初期化

	Primal_Dual_BellmanFord(int n) :

		V(n),

		G(n),

		dist(n, 0),

		prevv(n, 0),

		preve(n, 0),

		INF(std::numeric_limits<int>::max() / 8) {}

	void add_edge(int src, int dst, int cap, int cost) {

		// cost は weight に入れる

		G[src].emplace_back(src, dst, G[dst].size(), cost, cap);

		G[dst].emplace_back(dst, src, G[src].size() - 1, -cost, 0);

	}



	int min_cost_flow(int s, int t, int f) {

		int res = 0;

		while (f > 0) {

			// ベルマンフォードによりs-t最短路をもとめる

			dist.assign(V, INF);

			dist[s] = 0;

			bool update = true;

			while (update) {

				update = false;

				for (int v = 0; v < V; v++) {

					if (dist[v] == INF) continue;

					for (int i = 0; i < G[v].size(); i++) {

						Edge& e = G[v][i];

						if (e.cap > 0 && dist[e.dst] > dist[v] + e.cost) {

							dist[e.dst] = dist[v] + e.cost;

							prevv[e.dst] = v;

							preve[e.dst] = i;

							update = true;

						}

					}

				}

			}



			// これ以上流せない

			if (dist[t] == INF) {

				return -1;

			}



			// 復元したs-t最短路に沿って流せるだけ流す

			int d = f;

			// 尻からprevvを辿っていき、流せる量を求める

			for (int v = t; v != s; v = prevv[v]) {

				// 一つ手前に戻るための辺

				Edge &e = G[prevv[v]][preve[v]];

				chmin(d, e.cap);

			}



			f -= d;



			// ここでの dist はコスト和なので、それに流す量をかけると今回見つけた最短パスに流すコストとなる。

			res += d * dist[t];

			for (int v = t; v != s; v = prevv[v]) {

				Edge &e = G[prevv[v]][preve[v]];

				e.cap -= d;

				G[v][e.rev].cap += d;

			}

		}

		return res;

	}

};



/*

ダイクストラ版 Primal-Dual

出典: https://ei1333.github.io/luzhiled/snippets/graph/primal-dual.html

*/



template< typename flow_t, typename cost_t >

struct PrimalDual {

	const cost_t INF;



	struct edge {

		int to;

		flow_t cap;

		cost_t cost;

		int rev;

		bool isrev;

		edge(int aTo, flow_t aCap, cost_t aCost, int aRev, bool aIsRev) : to(aTo), cap(aCap), cost(aCost), rev(aRev), isrev(aIsRev) {}

	};

	vector< vector< edge > > graph;

	vector< cost_t > potential, min_cost;

	vector< int > prevv, preve;



	PrimalDual(int V) : graph(V), INF(numeric_limits< cost_t >::max()) {}



	void add_edge(int from, int to, flow_t cap, cost_t cost) {

		graph[from].emplace_back(to, cap, cost, (int)graph[to].size(), false);

		graph[to].emplace_back(from, 0, -cost, (int)graph[from].size() - 1, true);

	}



	cost_t min_cost_flow(int s, int t, flow_t f) {

		int V = (int)graph.size();

		cost_t ret = 0;

		using Pi = pair< cost_t, int >;

		priority_queue< Pi, vector< Pi >, greater< Pi > > que;

		potential.assign(V, 0);

		preve.assign(V, -1);

		prevv.assign(V, -1);



		while (f > 0) {

			min_cost.assign(V, INF);

			que.emplace(0, s);

			min_cost[s] = 0;

			while (!que.empty()) {

				Pi p = que.top();

				que.pop();

				if (min_cost[p.second] < p.first) continue;

				for (int i = 0; i < graph[p.second].size(); i++) {

					edge &e = graph[p.second][i];

					cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];

					if (e.cap > 0 && min_cost[e.to] > nextCost) {

						min_cost[e.to] = nextCost;

						prevv[e.to] = p.second, preve[e.to] = i;

						que.emplace(min_cost[e.to], e.to);

					}

				}

			}

			if (min_cost[t] == INF) return -1;

			for (int v = 0; v < V; v++) potential[v] += min_cost[v];

			flow_t addflow = f;

			for (int v = t; v != s; v = prevv[v]) {

				addflow = min(addflow, graph[prevv[v]][preve[v]].cap);

			}

			f -= addflow;

			ret += addflow * potential[t];

			for (int v = t; v != s; v = prevv[v]) {

				edge &e = graph[prevv[v]][preve[v]];

				e.cap -= addflow;

				graph[v][e.rev].cap += addflow;

			}

		}

		return ret;

	}



	void output() {

		for (int i = 0; i < graph.size(); i++) {

			for (auto &e : graph[i]) {

				if (e.isrev) continue;

				auto &rev_e = graph[e.to][e.rev];

				cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;

			}

		}

	}

};



class lca {

public:

	int n, segn;

	vector<int> path;		// 蟻本の vs、オイラーツアーを保持

	vector<int> depth;		// 蟻本の depth、path[i] であるノードの深さを保持

	vector<int> in_order;	// 蟻本の id、ノードiがオイラーツアーで最初に出てくるインデックスを保持

	vector<pair<int, int>> dat;

	const std::pair<int, int> INF = std::make_pair(1000000000, 1000000000);



	lca(const Graph& g, int root) : n(g.size()), path(n * 2 - 1), depth(n * 2 - 1), in_order(n) {

		int k = 0;

		dfs(g, root, -1, 0, k);



		// セグ木を構築、持つのはpair(depth, index) => depth が最小となる index がわかる 

		for (segn = 1; segn < n * 2 - 1; segn <<= 1);



		dat.assign(segn * 2, INF);

		for (int i = 0; i < (int)depth.size(); ++i) dat[segn + i] = std::make_pair(depth[i], i);

		for (int i = segn - 1; i >= 1; --i) dat[i] = min(dat[i * 2], dat[i * 2 + 1]);

	}



	int get(int u, int v) const {

		int l = std::min(in_order[u], in_order[v]);

		int r = std::max(in_order[u], in_order[v]) + 1;

		return path[range_min(1, segn, l, r).second];

	}



	void dfs(const Graph& g, int v, int p, int d, int& k) {

		// k: オイラーツアーの何番目かを保持する変数

		in_order[v] = k;

		path[k] = v;

		depth[k++] = d;

		for (auto &e : g[v]) {

			if (e.dst != p) {

				dfs(g, e.dst, v, d + 1, k);

				// ここに来た時はノードvの子であるe.dstを展開し終わってvに戻ってきたときなので、再度 path と depth に記録する

				path[k] = v;

				depth[k++] = d;

			}

		}

	}



	// v : いまみてるノード、w: 今見てるノードに対応する区間長 l: ? r: ?

	pair<int, int> range_min(int v, int w, int l, int r) const {

		if (r <= l || w == 0) return INF;

		if (r - l == w)

			return dat[v];



		int m = w / 2;

		auto rmin = range_min(v * 2, m, l, std::min(r, m));

		auto lmin = range_min(v * 2 + 1, m, std::max(0LL, l - m), r - m);



		return min(rmin, lmin);

	}

};



// int における ceil と floor、負数対応(a / b の ceil, floor)

int64_t intceil(int64_t a, int64_t b) {

	int sign_a = (a > 0) - (a < 0);

	int sign_b = (b > 0) - (b < 0);



	if (sign_a == sign_b) {

		return (a + b - sign_b) / b;

	}

	else {

		return a / b;

	}

}

int64_t intfloor(int64_t a, int64_t b) {

	int sign_a = (a > 0) - (a < 0);

	int sign_b = (b > 0) - (b < 0);



	if (sign_a == sign_b) {

		return a / b;

	}

	else {

		return (a - b + sign_b) / b;

	}

}



class Point {

public:

	int y, x;

	Point() { y = x = 0; }

	Point(int y0, int x0) {

		y = y0;

		x = x0;

	}

	Point operator+(const Point& p) const { return Point(y + p.y, x + p.x); }

	Point operator-(const Point& p) const { return Point(y - p.y, x - p.x); }

	Point operator*(int a) const { return Point(y * a, x * a); }

	long long length2() const { return y * (long long)y + x * (long long)x; }

	long long dist2(const Point& p) const {

		return (y - p.y) * (long long)(y - p.y) + (x - p.x) * (long long)(x - p.x);

	}

	long long dot(const Point& p) const {

		return y * (long long)p.y + x * (long long)p.x;  // |a|*|b|*cosθ

	}

	long long cross(const Point& p) const {

		return x * (long long)p.y - y * (long long)p.x;  // |a|*|b|*sinθ

	}



	static bool Sorter(const Point& p1, const Point& p2) {

		bool a = p1.y > 0 || (p1.y == 0 && p1.x >= 0);

		bool b = p2.y > 0 || (p2.y == 0 && p2.x >= 0);

		if (a != b) return a;

		long long c = p2.x * (long long)p1.y;

		long long d = p1.x * (long long)p2.y;

		if (c != d) return c < d;

		return p1.length2() < p2.length2();

	}

};





int solve(ostringstream& aout, long long S);

void solve_TLE(ostringstream& aout, long long S);



class StressTest {

private:

	mt19937 m_RandEngine;

	bool judge_case(long long S) {

		ostringstream fast, tle;

		solve(fast, S);

		solve_TLE(tle, S);

		if (fast.str() == tle.str()) {

			return true;

		}

		else {

			return false;

		}

	}

	// [l, l+1, ... r] の数列を生成し、シャッフルする

	vector<int> create_range_permutation(int l, int r) {

		vector<int> ret;

		for (int i = l; i <= r; i++) {

			ret.push_back(i);

		}

		shuffle(ret.begin(), ret.end(), m_RandEngine);

		return ret;

	}

	// [1, n] の順列を生成する

	vector<int> create_permutation(int n) {

		create_range_permutation(1, n);

	}

	// 範囲が[l, r] でサイズが n の数列を生成する

	vector<int> create_random_sequence(int l, int r, int n) {

		uniform_int_distribution<> randLR(l, r);

		vector<int> ret;

		for (int i = 0; i < n; i++) {

			ret.push_back(randLR(m_RandEngine));

		}

		return ret;

	}



	/*

	* 頂点数 n, 辺数 m で自己ループと多重辺のない無向グラフを生成

	* 慣習的に頂点番号が1-indexed な AtCoder で 1-n の頂点が使えるようにするため n+1 頂点のグラフを生成し、0番を無視することとする

	* weighted を true にすると重み付き、maxWeight で最大重みを指定

	* 連結でないグラフが出力される可能性があることに注意する

	*/

	Graph create_undirected_graph(int n, int m, bool weighted = false, int maxWeight = 10) {

		Graph ret(n + 1);

		set<pair<int, int>> used;

		uniform_int_distribution<> randNode(1, n);

		uniform_int_distribution<> randWeight(1, maxWeight);

		while (used.size() < m * 2) {

			int src = randNode(m_RandEngine);

			int dst = randNode(m_RandEngine);



			// 自己ループ、多重辺判定

			if (used.count(make_pair(src, dst)) == 0 && used.count(make_pair(dst, src)) == 0 && src != dst) {

				used.insert(make_pair(src, dst));

				used.insert(make_pair(dst, src));

				add_edge(ret, src, dst, weighted ? randWeight(m_RandEngine) : 1);

			}

		}

		return ret;

	}



	/*

	* 頂点数 n, 辺数 m で自己ループと多重辺のない有向グラフを生成

	* 慣習的に頂点番号が1-indexed な AtCoder で 1-n の頂点が使えるようにするため n+1 頂点のグラフを生成し、0番を無視することとする

	* weighted を true にすると重み付き、maxWeight で最大重みを指定

	* 連結でないグラフが出力される可能性があることに注意する

	*/

	Graph create_directed_graph(int n, int m, bool weighted = false, int maxWeight = 10) {

		Graph ret(n + 1);

		set<pair<int, int>> used;

		uniform_int_distribution<> randNode(1, n);

		uniform_int_distribution<> randWeight(1, maxWeight);

		while (used.size() < m) {

			int src = randNode(m_RandEngine);

			int dst = randNode(m_RandEngine);



			// 自己ループ、多重辺判定

			if (used.count(make_pair(src, dst)) == 0 && src != dst) {

				used.insert(make_pair(src, dst));

				add_arc(ret, src, dst, weighted ? randWeight(m_RandEngine) : 1);

			}

		}

		return ret;

	}



	/*

	* 頂点数nの木(無向)を生成します。

	*/

	Graph create_tree(int n, bool weighted = false, int maxWeight = 10) {

		Graph ret(n + 1);

		uf_tree uf(n + 1);

		int cnt = 0;



		uniform_int_distribution<> randNode(1, n);

		uniform_int_distribution<> randWeight(1, maxWeight);



		while (cnt < n - 1) {

			int n1 = randNode(m_RandEngine);

			int n2 = randNode(m_RandEngine);

			if (n1 != n2 && !uf.is_same(n1, n2)) {

				cnt++;

				add_edge(ret, n1, n2, weighted ? randWeight(m_RandEngine) : 1);

			}

		}

	}

public:

	StressTest(int seed) :

		m_RandEngine(seed) {}

	void test() {

		while (1) {

			// TODO: generate random case

			//if (!judge_case(S)) {

			// TODO: output case

			//break;

			//}

		}

	}

};



int solve(ostringstream& aout, long long S) {

	// 区間sum, 区間chg

	auto myAdd = [](int a, int b) -> int {

		return (a + b) % mod;

	};

	auto myChg = [](int a, int b) -> int {

		return b;

	};



	// 区間更新はしない

	vector<SegmentTree<int, int>> dp(S + 10, SegmentTree<int, int>(S + 10, myAdd, myChg, myChg, 0, LL_HALFMAX));



	// dp[0][0] = 1;

	dp[0].update(0, 1);



	// もらう

	REPS(i, S) {

		REP(j, 3, S + 1) {

			int chg = dp[i - 1].query(0, j - 3 + 1);

			dp[i].update(j, chg);

		}

	}



	int ans = 0;

	REPS(i, S) {

		int add = dp[i].query(S);

		ans += add;

		ans %= mod;

	}



	return ans;

}



void solve_TLE(ostringstream& aout, long long S) {



}



signed ans[] = { 0, 0, 1, 1, 1, 2, 3, 4, 6, 9, 13, 19, 28, 41, 60, 88, 129, 189, 277, 406, 595, 872, 1278, 1873, 2745, 4023, 5896, 8641, 12664, 18560, 27201, 39865, 58425, 85626, 125491, 183916, 269542, 395033, 578949, 848491, 1243524, 1822473, 2670964, 3914488, 5736961, 8407925, 12322413, 18059374, 26467299, 38789712, 56849086, 83316385, 122106097, 178955183, 262271568, 384377665, 563332848, 825604416, 209982074, 773314922, 598919331, 808901405, 582216320, 181135644, 990037049, 572253362, 753389006, 743426048, 315679403, 69068402, 812494450, 128173846, 197242248, 9736691, 137910537, 335152785, 344889476, 482800013, 817952798, 162842267, 645642280, 463595071, 626437338, 272079611, 735674682, 362112013, 634191624, 369866299, 731978312, 366169929, 736036228, 468014533, 834184462, 570220683, 38235209, 872419671, 442640347, 480875556, 353295220, 795935567, 276811116, 630106336, 426041896, 702853012, 332959341, 759001237, 461854242, 794813583, 553814813, 15669048, 810482631, 364297437, 379966485, 190449109, 554746546, 934713031, 125162133, 679908679, 614621703, 739783836, 419692508, 34314204, 774098040, 193790541, 228104745, 2202778, 195993319, 424098064, 426300842, 622294161, 46392218, 472693060, 94987214, 141379432, 614072492, 709059706, 850439138, 464511623, 173571322, 24010453, 488522076, 662093398, 686103851, 174625920, 836719318, 522823162, 697449082, 534168393, 56991548, 754440630, 288609016, 345600564, 100041187, 388650203, 734250767, 834291954, 222942150, 957192917, 791484864, 14427007, 971619924, 763104781, 777531788, 749151705, 512256479, 289788260, 38939958, 551196437, 840984697, 879924655, 431121085, 272105775, 152030423, 583151508, 855257283, 7287699, 590439207, 445696483, 452984182, 43423382, 489119865, 942104047, 985527429, 474647287, 416751327, 402278749, 876926036, 293677356, 695956105, 572882134, 866559490, 562515588, 135397715, 1957198, 564472786, 699870501, 701827699, 266300478, 966170979, 667998671, 934299149, 900470121, 568468785, 502767927, 403238041, 971706826, 474474746, 877712787, 849419606, 323894345, 201607125, 51026724, 374921069, 576528194, 627554918, 2475980, 579004174, 206559085, 209035065, 788039239, 994598324, 203633382, 991672621, 986270938, 189904313, 181576927, 167847858, 357752171, 539329098, 707176956, 64929120, 604258218, 311435167, 376364287, 980622505, 292057665, 668421952, 649044450, 941102115, 609524060, 258568503, 199670611, 809194671, 67763167, 267433778, 76628442, 144391609, 411825387, 488453829, 632845438, 44670818, 533124647, 165970078, 210640896, 743765543, 909735621, 120376510, 864142053, 773877667, 894254177, 758396223, 532273883, 426528053, 184924269, 717198152, 143726198, 328650467, 45848612, 189574810, 518225277, 564073889, 753648699, 271873969, 835947858, 589596550, 861470519, 697418370, 287014913, 148485425, 845903795, 132918701, 281404126, 127307914, 260226615, 541630741, 668938655, 929165270, 470796004, 139734652, 68899915, 539695919, 679430571, 748330486, 288026398, 967456969, 715787448, 3813839, 971270808, 687058249, 690872088, 662142889, 349201131, 40073212, 702216101, 51417225, 91490437, 793706538, 845123763, 936614200, 730320731, 575444487, 512058680, 242379404, 817823891, 329882564, 572261968, 390085852, 719968416, 292230377, 682316229, 402284638, 694515015, 376831237, 779115875, 473630883, 850462120, 629577988, 103208864, 953670984, 583248965, 686457829, 640128806, 223377764, 909835593, 549964392, 773342156, 683177742, 233142127, 6484276, 689662018, 922804145, 929288421, 618950432, 541754570, 471042984, 89993409, 631747979, 102790956, 192784365, 824532344, 927323300, 120107658, 944640002, 871963295, 992070953, 936710948, 808674236, 800745182, 737456123, 546130352, 346875527, 84331643, 630461995, 977337522, 61669158, 692131153, 669468668, 731137826, 423268972, 92737633, 823875459, 247144424, 339882057, 163757509, 410901933, 750783990, 914541499, 325443425, 76227408, 990768907, 316212325, 392439733, 383208633, 699420958, 91860684, 475069317, 174490268, 266350952, 741420269, 915910537, 182261482, 923681751, 839592281, 21853756, 945535507, 785127781, 806981537, 752517037, 537644811, 344626341, 97143371, 634788182, 979414523, 76557887, 711346069, 690760585, 767318472, 478664534, 169425112, 936743584, 415408111, 584833223, 521576800, 936984911, 521818127, 43394920, 980379831, 502197951, 545592871, 525972695, 28170639, 573763510, 99736198, 127906837, 701670347, 801406545, 929313382, 630983722, 432390260, 361703635, 992687357, 425077610, 786781245, 779468595, 204546198, 991327443, 770796031, 975342229, 966669665, 737465689, 712807911, 679477569, 416943251, 129751155, 809228724, 226171968, 355923123, 165151840, 391323808, 747246931, 912398771, 303722572, 50969496, 963368267, 267090832, 318060328, 281428588, 548519420, 866579748, 148008329, 696527749, 563107490, 711115819, 407643561, 970751051, 681866863, 89510417, 60261461, 742128324, 831638741, 891900202, 634028519, 465667253, 357567448, 991595967, 457263213, 814830661, 806426621, 263689827, 78520481, 884947102, 148636922, 227157403, 112104498, 260741420, 487898823, 600003321, 860744741, 348643557, 948646878, 809391612, 158035162, 106682033, 916073645, 74108800, 180790833, 96864471, 170973271, 351764104, 448628575, 619601846, 971365950, 419994518, 39596357, 10962300, 430956818, 470553175, 481515475, 912472293, 383025461, 864540936, 777013222, 160038676, 24579605, 801592827, 961631503, 986211108, 787803928, 749435424, 735646525, 523450446, 272885863, 8532381, 531982827, 804868690, 813401071, 345383891, 150252574, 963653645, 309037529, 459290103, 422943741, 731981270, 191271366, 614215107, 346196370, 537467736, 151682836, 497879206, 35346935, 187029771, 684908977, 720255912, 907285683, 592194653, 312450558, 219736234, 811930887, 124381438, 344117672, 156048552, 280429990, 624547662, 780596214, 61026197, 685573859, 466170066, 527196263, 212770115, 678940181, 206136437, 418906552, 97846726, 303983163, 722889715, 820736441, 124719597, 847609312, 668345746, 793065343, 640674648, 309020387, 102085723, 742760371, 51780751, 153866474, 896626845, 948407596, 102274063, 998900908, 947308497, 49582553, 48483454, 995791951, 45374497, 93857951, 89649895, 135024392, 228882343, 318532238, 453556630, 682438973, 971204, 454527834, 136966800, 137938004, 592465838, 729432638, 867370642, 459836473, 189269104, 56639739, 516476212, 705745316, 762385055, 278861260, 984606576, 746991624, 25852877, 10459446, 757451070, 783303947, 793763393, 551214456, 334518396, 128281782, 679496238, 14014627, 142296409, 821792647, 835807274, 978103683, 799896323, 635703590, 613807266, 413703582, 49407165, 663214431, 76918006, 126325171, 789539602, 866457608, 992782779, 782322374, 648779975, 641562747, 423885114, 72665082, 714227829, 138112936, 210778018, 925005847, 63118776, 273896794, 198902634, 262021410, 535918204, 734820838, 996842248, 532760445, 267581276, 264423517, 797183962, 64765231, 329188748, 126372703, 191137934, 520326682, 646699385, 837837319, 358163994, 4863372, 842700691, 200864678, 205728050, 48428734, 249293412, 455021462, 503450196, 752743608, 207765063, 711215259, 463958860, 671723923, 382939175, 846898035, 518621951, 901561126, 748459154, 267081098, 168642217, 917101371, 184182462, 352824679, 269926043, 454108505, 806933184, 76859220, 530967725, 337900902, 414760122, 945727847, 283628742, 698388864, 644116704, 927745446, 626134303, 270251000, 197996439, 824130742, 94381735, 292378174, 116508909, 210890644, 503268818, 619777727, 830668371, 333937182, 953714909, 784383273, 118320448, 72035350, 856418623, 974739071, 46774414, 903193037, 877932101, 924706515, 827899545, 705831639, 630538147, 458437685, 164269317, 794807464, 253245142, 417514459, 212321916, 465567058, 883081517, 95403426, 560970484, 444051994, 539455420, 100425897, 544477891, 83933304, 184359201, 728837092, 812770396, 997129597, 725966682, 538737071, 535866661, 261833336, 800570407, 336437061, 598270397, 398840797, 735277858, 333548248, 732389045, 467666896, 801215144, 533604182, 1271071, 802486215, 336090390, 337361461, 139847669, 475938059, 813299520, 953147189, 429085241, 242384754, 195531936, 624617177, 867001931, 62533860, 687151037, 554152961, 616686821, 303837851, 857990812, 474677626, 778515477, 636506282, 111183901, 889699378, 526205653, 637389554, 527088925, 53294571, 690684125, 217773043, 271067614, 961751739, 179524775, 450592389, 412344121, 591868896, 42461278, 454805399, 46674288, 89135566, 543940965, 590615253, 679750819, 223691777, 814307030, 494057842, 717749619, 532056642, 26114477, 743864096, 275920731, 302035208, 45899297, 321820028, 623855236, 669754533, 991574561, 615429790, 285184316, 276758870, 892188660, 177372969, 454131839, 346320492, 523693461, 977825300, 324145785, 847839246, 825664539, 149810317, 997649563, 823314095, 973124412, 970773968, 794088056, 767212461, 737986422, 532074471, 299286925, 37273340, 569347811, 868634736, 905908076, 475255880, 343890609, 249798678, 725054558, 68945160, 318743838, 43798389, 112743549, 431487387, 475285776, 588029325, 19516705, 494802481, 82831799, 102348504, 597150985, 679982784, 782331288, 379482266, 59465043, 841796331, 221278590, 280743633, 122539957, 343818547, 624562180, 747102137, 90920677, 715482857, 462584987, 553505664, 268988514, 731573501, 285079158, 554067672, 285641166, 570720324, 124787989, 410429155, 981149479, 105937461, 516366616, 497516088, 603453549, 119820158, 617336246, 220789788, 340609946, 957946192, 178735973, 519345919, 477292104, 656028077, 175373989, 652666093, 308694163, 484068152, 136734238, 445428401, 929496553, 66230784, 511659185, 441155731, 507386515, 19045693, 460201424, 967587939, 986633632, 446835049, 414422981, 401056606, 847891655, 262314629, 663371235, 511262883, 773577512, 436948740, 948211623, 721789128, 158737861, 106949477, 828738605, 987476466, 94425936, 923164541, 910641000, 5066929, 928231470, 838872463, 843939392, 772170855, 611043311, 454982696, 227153544, 838196855, 293179544, 520333088, 358529936, 651709480, 172042561, 530572497, 182281970, 354324531, 884897028, 67178991, 421503522, 306400543, 373579534, 795083056, 101483592, 475063126, 270146175, 371629767, 846692893, 116839061, 488468828, 335161714, 452000775, 940469603, 275631310, 727632085, 668101681, 943732991, 671365069, 339466743, 283199727, 954564796, 294031532, 577231259, 531796048, 825827580, 403058832, 934854880, 760682453, 163741278, 98596151, 859278604, 23019875, 121616026, 980894630, 3914498, 125530524, 106425147, 110339645, 235870169, 342295316, 452634961, 688505130, 30800439, 483435400, 171940523, 202740962, 686176362, 858116885, 60857840, 747034202, 605151080, 666008920, 413043115, 18194188, 684203108, 97246216, 115440404, 799643512, 896889728, 12330125, 811973637, 708863358, 721193483, 533167113, 242030464, 963223947, 496391053, 738421517, 701645457, 198036503, 936458020, 638103470, 836139973, 772597986, 410701449, 246841415, 19439394, 430140843, 676982258, 696421652, 126562488, 803544746, 499966391, 626528879, 430073618, 930040009, 556568881, 986642499, 916682501, 473251375, 459893867, 376576361, 849827736, 309721596, 686297957, 536125686, 845847282, 532145232, 68270911, 914118193, 446263418, 514534329, 428652515, 874915933, 389450255, 818102770, 693018696, 82468944, 900571714, 593590403, 676059347, 576631054, 170221450, 846280797, 422911844, 593133294, 439414084, 862325928, 455459215, 894873299, 757199220, 212658428, 107531720, 864730940, 77389361, 184921081, 49652014, 127041375, 311962456, 361614470, 488655845, 800618301, 162232764, 650888609, 451506903, 613739667, 264628269, 716135172, 329874832, 594503101, 310638266, 640513098, 235016192, 545654458, 186167549, 421183741, 966838199, 153005741, 574189482, 541027674, 694033415, 268222890, 809250564, 503283972, 771506862, 580757419, 84041384, 855548246, 436305658, 520347042, 375895281, 812200939, 332547974, 708443255, 520644187, 853192161, 561635409, 82279589, 935471750, 497107152, 579386741, 514858484, 11965629, 591352370, 106210847, 118176476, 709528846, 815739693, 933916169, 643445008, 459184694, 393100856, 36545857, 495730551, 888831407, 925377264, 421107808, 309939208, 235316465, 656424273, 966363481, 201679939, 858104212, 824467686, 26147618, 884251830, 708719509, 734867127, 619118950, 327838452, 62705572, 681824522, 9662967, 72368539, 754193061, 763856028, 836224567, 590417621, 354273642, 190498202, 780915823, 135189458, 325687660, 106603476, 241792934, 567480594, 674084070, 915877004, 483357591, 157441654, 73318651, 556676242, 714117896, 787436547, 344112782, 58230671, 845667218, 189779993, 248010664, 93677875, 283457868, 531468532, 625146407, 908604275, 440072800, 65219200, 973823475, 413896268, 479115468, 452938936, 866835204, 345950665, 798889601, 665724798, 11675456, 810565057, 476289848, 487965304, 298530354, 774820202, 262785499, 561315853, 336136048, 598921547, 160237393, 496373441, 95294981, 255532374, 751905815, 847200796, 102733163, 854638978, 701839767, 804572930, 659211901, 361051661, 165624584, 824836485, 185888139, 351512723, 176349201, 362237340, 713750063, 890099264, 252336597, 966086660, 856185917, 108522507, 74609160, 930795077, 39317577, 113926737, 44721807, 84039384, 197966121, 242687928, 326727312, 524693433, 767381361, 94108666, 618802099, 386183453, 480292119, 99094211, 485277664, 965569783, 64663987, 549941651, 515511427, 580175414, 130117058, 645628485, 225803892, 355920950, 1549428, 227353320, 583274270, 584823698, 812177018, 395451281, 980274979, 792451990, 187903264, 168178236, 960630226, 148533483, 316711719, 277341938, 425875421, 742587140, 19929071, 445804492, 188391625, 208320696, 654125188, 842516813, 50837502, 704962690, 547479496, 598316998, 303279681, 850759177, 449076168, 752355849, 603115019, 52191180, 804547029, 407662041, 459853221, 264400243, 672062284, 131915498, 396315741, 68378018, 200293516, 596609257, 664987275, 865280791, 461890041, 126877309, 992158100, 454048134, 580925443, 573083536, 27131663, 608057106, 181140635, 208272298, 816329404, 997470039, 205742330, 22071727, 19541759, 225284089, 247355816, 266897575, 492181664, 739537480, 6435048, 498616712, 238154185, 244589233, 743205945, 981360130, 225949356, 969155301, 950515424, 176464773, 145620067, 96135484, 272600257, 418220324, 514355808, 786956065, 205176382, 719532190, 506488248, 711664630, 431196813, 937685061, 649349684, 80546490, 18231544, 667581228, 748127718, 766359262, 433940483, 182068194, 948427456, 382367932, 564436126, 512863575, 895231507, 459667626, 972531201, 867762701, 327430320, 299961514, 167724208, 495154528, 795116042, 962840250, 457994771, 253110806, 215951049, 673945820, 927056626, 143007668, 816953488, 744010107, 887017775, 703971256, 447981356, 334999124, 38970373, 486951729, 821950853, 860921226, 347872948, 169823794, 30745013, 378617961, 548441755, 579186768, 957804729, 506246477, 85433238, 43237960, 549484437, 634917675, 678155635, 227640065, 862557740, 540713368, 768353433, 630911166, 171624527, 939977960, 570889119, 742513646, 682491599, 253380711, 995894357, 678385949, 931766660, 927661010, 606046952, 537813605, 465474608, 71521553, 609335158, 74809759, 146331312, 755666470, 830476229, 976807541, 732474004, 562950226, 539757760, 272231757, 835181983, 374939736, 647171493, 482353469, 857293205, 504464691, 986818160, 844111358, 348576042, 335394195, 179505546, 528081588, 863475783, 42981322, 571062910, 434538686, 477520008, 48582911, 483121597, 960641605, 9224509, 492346106, 452987704, 462212213, 954558319, 407546016, 869758229, 824316541, 231862550, 101620772, 925937313, 157799856, 259420628, 185357934, 343157790, 602578418, 787936352, 131094135, 733672553, 521608898, 652703033, 386375579, 907984477, 560687503, 947063082, 855047552, 415735048, 362798123, 217845668, 633580716, 996378839, 214224500, 847805216, 844184048, 58408541, 906213757, 750397798, 808806339, 715020089, 465417880, 274224212, 989244301, 454662174, 728886386, 718130680, 172792847, 901679233, 619809906, 792602753, 694281979, 314091878, 106694624, 800976603, 115068474, 221763098, 22739694, 137808168, 359571266, 382310960, 520119128, 879690394, 262001347, 782120475, 661810862, 923812209, 705932677, 367743532, 291555734, 997488411, 365231936, 656787670, 654276074, 19508003, 676295673, 330571740, 350079743, 26375409, 356947149, 707026892, 733402301, 90349443, 797376335, 530778629, 621128072, 418504400, 949283029, 570411094, 988915494, 938198516, 508609603, 497525090, 435723599, 944333202, 441858285, 877581884, 821915079, 263773357, 141355234, 963270313, 227043663, 368398897, 331669203, 558712866, 927111763, 258780959, 817493825, 744605581, 3386533, 820880358, 565485932, 568872465, 389752816, 955238748, 524111206, 913864022, 869102763, 393213962, 307077977, 176180733, 569394695, 876472672, 52653398, 622048093, 498520758, 551174156, 173222242, 671743000, 222917149, 396139391, 67882384, 290799533, 686938924, 754821308, 45620834, 732559758, 487381059, 533001893, 265561644, 752942703, 285944589, 551506233, 304448929, 590393518, 141899744, 446348673, 36742184, 178641928, 624990601, 661732785, 840374713, 465365307, 127098085, 967472798, 432838098, 559936183, 527408974, 960247072, 520183248, 47592215, 7839280, 528022528, 575614743, 583454023, 111476544, 687091287, 270545303, 382021847, 69113127, 339658430, 721680277, 790793404, 130451827, 852132104, 642925501, 773377328, 625509425, 268434919, 41812240, 667321665, 935756584, 977568824, 644890482, 580647059, 558215876, 203106351, 783753410, 341969279, 545075630, 328829033, 670798312, 215873935, 544702968, 215501273, 431375208, 976078176, 191579442, 622954650, 599032819, 790612261, 413566904, 12599716, 803211977, 216778874, 229378590, 32590560, 249369434, 478748024, 511338584, 760708018, 239456035, 750794619, 511502630, 750958665, 501753277, 13255900, 764214565, 265967835, 279223735, 43438293, 309406128, 588629863, 632068156, 941474284, 530104140, 162172289, 103646566, 633750706, 795922995, 899569561, 533320260, 329243248, 228812802, 762133062, 91376303, 320189105, 82322160, 173698463, 493887568, 576209728, 749908191, 243795752, 820005480, 569913664, 813709416, 633714889, 203628546, 17337955, 651052844, 854681390, 872019345, 523072182, 377753565, 249772903, 772845085, 150598643, 400371546, 173216624, 323815267, 724186813, 897403437, 221218697, 945405510, 842808940, 64027630, 9433133, 852242073, 916269703, 925702836, 777944902, 694214598, 619917427, 397862322, 92076913, 711994340, 109856655, 201933568, 913927908, 23784556, 225718124, 139646025, 163430581, 389148705, 528794730, 692225311, 81374009, 610168739, 302394043, 383768052, 993936791, 296330827, 680098879, 674035663, 970366490, 650465362, 324501018, 294867501, 945332863, 269833874, 564701375, 510034231, 779868105, 344569473, 854603704, 634471802, 979041275, 833644972, 468116767, 447158035, 280803000, 748919767, 196077795, 476880795, 225800555, 421878350, 898759145, 124559693, 546438043, 445197181, 569756874, 116194910, 561392091, 131148958, 247343868, 808735959, 939884917, 187228778, 995964737, 935849647, 123078418, 119043148, 54892788, 177971206, 297014354, 351907142, 529878348, 826892702, 178799837, 708678185, 535570880, 714370717, 423048895, 958619775, 672990485, 96039373, 54659141, 727649626, 823688999, 878348140, 605997759, 429686751, 308034884, 914032643, 343719387, 651754271, 565786907, 909506294, 561260558, 127047458, 36553745, 597814303, 724861761, 761415506, 359229802, 84091556, 845507062, 204736857, 288828413, 134335468, 339072325, 627900738, 762236206, 101308524, 729209262, 491445461, 592753985, 321963240, 813408701, 406162679, 728125919, 541534613, 947697292, 675823204, 217357810, 165055095, 840878299, 58236102, 223291197, 64169489, 122405591, 345696788, 409866277, 532271868, 877968656, 287834926, 820106794, 698075443, 985910369, 806017156, 504092592, 490002954, 296020103, 800112695, 290115642, 586135745, 386248433, 676364075, 262499813, 648748246, 325112314, 587612127, 236360366, 561472680, 149084800, 385445166, 946917846, 96002639, 481447805, 428365644, 524368283, 5816081, 434181725, 958550008, 964366089, 398547807, 357097808, 321463890, 720011697, 77109498, 398573388, 118585078, 195694576, 594267964, 712853042, 908547618, 502815575, 215668610, 124216221, 627031796, 842700406, 966916627, 593948416, 436648815, 403565435, 997513851, 434162659, 837728094, 835241938, 269404590, 107132677, 942374615, 211779198, 318911875, 261286483, 473065681, 791977556, 53264032, 526329713, 318307262, 371571294, 897901007, 216208262, 587779556, 485680556, 701888818, 289668367, 775348923, 477237734, 766906101, 542255017, 19492744, 786398845, 328653855, 348146599, 134545437, 463199292, 811345891, 945891328, 409090613, 220436497, 166327818, 575418431, 795854928, 962182746, 537601170, 333456091, 295638830, 833240000, 166696084, 462334914, 295574907, 462270991, 924605905, 220180805, 682451796, 607057694, 827238499, 509690288, 116747975, 943986474, 453676755, 570424730, 514411197, 968087952, 538512675, 52923865, 21011810, 559524485, 612448350, 633460160, 192984638, 805432988, 438893141, 631877779, 437310760, 876203901, 508081673, 945392433, 821596327, 329677993, 275070419, 96666739, 426344732, 701415151, 798081890, 224426615, 925841766, 723923649, 948350264, 874192023, 598115665, 546465922, 420657938, 18773596, 565239518, 985897456, 4671045, 569910563, 555808012, 560479057, 130389613, 686197625, 246676675, 377066288, 63263906, 309940581, 687006869, 750270775, 60211349, 747218218, 497488986, 557700335, 304918546, 802407532, 360107860, 665026406, 467433931, 827541791, 492568190, 960002121, 787543905, 280112088, 240114202, 27658100, 307770188, 547884390, 575542490, 883312678};



signed main() {

	int S;

	scanf("%lld", &S);



	printf("%lld\n", ans[S - 1]);



	return 0;

}
