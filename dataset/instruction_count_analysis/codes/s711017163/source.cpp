#include "iostream"

#include "climits"

#include "list"

#include "queue"

#include "stack"

#include "set"

#include "functional"

#include "algorithm"

#include "string"

#include "map"

#include "unordered_map"

#include "unordered_set"

#include "iomanip"

#include "cmath"

#include "random"

#include "bitset"

#include "cstdio"

#include "numeric"

#include "cassert"

#include "ctime"



using namespace std;



//constexpr long long int MOD = 1000000007;

//constexpr int MOD = 1000000007;

//constexpr int MOD = 998244353;

constexpr long long int MOD = 998244353;

constexpr double EPS = 1e-12;



//int N, M, K, T, H, W, L, R;

long long int N, M, K, T, H, W, L, R;



// BEGIN CUT

// 更新が区間chmin クエリが区間和と区間max



long long int LLINF = MOD * MOD;





using ll = long long;



template<typename dat_type, typename lazy_type>

struct segtree {

	ll n;

	vector<dat_type> dat;

	dat_type dat_d;

	vector<lazy_type> lazy;

	lazy_type lazy_d;



	using F = function<dat_type(dat_type, dat_type)>;

	F merge_dat;



	segtree() {}

	segtree(int n_, F md, dat_type dd, ll ld)

		: dat_d(dd), lazy_d(ld), merge_dat(md)

	{

		n = 1; while (n < n_) n *= 2;

		dat.assign(n * 2, dat_d);

		lazy.assign(n * 2, lazy_d);

	}



	void build(vector<dat_type> v) {

		for(int i=0;i<v.size();i++)dat[i + n - 1] = v[i];

		//REP(i, v.size()) dat[i + n - 1] = v[i];

		for (int i = n - 2; i >= 0; --i) {

			dat[i] = merge_dat(dat[i * 2 + 1], dat[i * 2 + 2]);

		}

	}



	void eval(int k, int l, int r) {

		if (lazy[k] == lazy_d) return;

		// dat[k] に lazy[k] を作用させる

		if (dat[k].max > lazy[k]) {

			dat[k].sum -= (dat[k].max - lazy[k]) * dat[k].cnt;

			dat[k].max = lazy[k];

		}

		if (k * 2 + 1 < n * 2 - 1) {

			// lazy[k] を下に伝播させる

			if (lazy[2 * k + 1] > lazy[k]) {

				lazy[2 * k + 1] = lazy[k];

			}

			if (lazy[2 * k + 2] > lazy[k]) {

				lazy[2 * k + 2] = lazy[k];

			}

			//chmin(lazy[2 * k + 1], lazy[k]);

			//chmin(lazy[2 * k + 2], lazy[k]);

		}

		lazy[k] = lazy_d;

	}



	void update(int a, int b, ll x, int k, int l, int r) {

		eval(k, l, r);

		// break_condition

		if (b <= l || r <= a || dat[k].max <= x) return;

		// tag_condition

		if (a <= l && r <= b && dat[k].second < x) {

			// lazyへ値を代入

			lazy[k] = x;

			eval(k, l, r);

			return;

		}

		int m = (l + r) >> 1;

		update(a, b, x, 2 * k + 1, l, m);

		update(a, b, x, 2 * k + 2, m, r);

		dat[k] = merge_dat(dat[2 * k + 1], dat[2 * k + 2]);

	}

	void update(int a, int b, ll x) { update(a, b, x, 0, 0, n); }



	dat_type query(int a, int b, int k, int l, int r) {

		eval(k, l, r);

		if (b <= l || r <= a) return dat_d;

		if (a <= l && r <= b) return dat[k];



		int m = (l + r) >> 1;

		dat_type vl = query(a, b, 2 * k + 1, l, m);

		dat_type vr = query(a, b, 2 * k + 2, m, r);

		return merge_dat(vl, vr);

	}

	dat_type query(int a, int b) { return query(a, b, 0, 0, n); }

};



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);



	cin >> N >> K;

	long long int sum = (N - 2)*(N - 2);



	struct node {

		ll sum, max, second, cnt;

		node(ll v = 0) : sum(v), max(v), second(-LLINF), cnt(1) {}

	};

	auto merge_dat = [](node l, node r) {

		node ret;

		ret.sum = l.sum + r.sum;

		ret.max = max(l.max, r.max);

		if (ret.max == l.max && ret.max == r.max) {

			ret.second = max(l.second, r.second);

			ret.cnt = l.cnt + r.cnt;

		}

		else {

			ret.cnt = l.max > r.max ? l.cnt : r.cnt;

			ret.second = max({ min(l.max, r.max), l.second, r.second });

		}

		assert(ret.max != ret.second);

		return ret;

	};

	segtree<node, ll> xsg(N, merge_dat, node(), LLINF);

	segtree<node, ll> ysg(N, merge_dat, node(), LLINF);

	for (int i = 0; i < N; i++) {

		ll a;

		//cin >> a;

		xsg.dat[i + xsg.n - 1] = node(N - 1);

		ysg.dat[i + xsg.n - 1] = node(N - 1);

	}

	for (int i = xsg.n - 2; i >= 0; --i) {

		xsg.dat[i] = merge_dat(xsg.dat[i * 2 + 1], xsg.dat[i * 2 + 2]);

		ysg.dat[i] = merge_dat(ysg.dat[i * 2 + 1], ysg.dat[i * 2 + 2]);

	}

	while (K--) {

		cin >> L;

		if (L == 1) {

			int x;

			cin >> x;

			x--;

			int box = xsg.query(x, x + 1).max;

			sum -= max(0,box-1);

			ysg.update(1, box, x);

		}

		else {

			int y;

			cin >> y;

			y--;

			int box = ysg.query(y, y + 1).max;

			sum -= max(0,box-1);

			xsg.update(1, box, y);

		}

	}

	cout << sum << endl;

}