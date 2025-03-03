#include "stdc++.h"

using namespace std;

using ll = long long;



struct RS {

	using type = ll;

	static type id() { return 0; }

	static type op(const type& l, const type& r) {

		return l + r;

	}

};



class seg_node {

public:

	using M = RS;

	using T = typename M::type;

	using U = ll;



	T get() const {

		return val + lazy * size;

	}

	void update(U v) {

		lazy += v;

	}

	bool is_updated() const {

		return lazy;

	}

	void push(seg_node& l, seg_node& r) {

		if (lazy == 0) return;

		l.update(lazy);

		r.update(lazy);

		val = get();

		lazy = 0;

	}

	void init(const seg_node& l, const seg_node& r) {

		size = l.size + r.size;

	}

	void init(const T& v) {

		val = v;

	}

	seg_node() : val(M::id()), size(1), lazy(0) {}



public:

	T val;



private:

	int size;

	U lazy;



};



class segment_tree {

	using M = typename seg_node::M;

	using T = typename seg_node::T;

	using U = typename seg_node::U;

	const int h, n;

	vector<seg_node> data;

	void push(int node) {

		data[node].push(data[node << 1], data[(node << 1) | 1]);

	}

	void update(int node) {

		data[node].val = M::op(data[node << 1].get(), data[(node << 1) | 1].get());

	}

public:

	segment_tree(int n_)

		: h(ceil(log2(n_))), n(1 << h), data(n * 2) {

		init();

	}

	segment_tree(int n_, T v1)

		: h(ceil(log2(n_))), n(1 << h), data(n * 2) {

		for (int i = 0; i < n_; i++) {

			data[i + n].init(v1);

		}

		init();

	}

	segment_tree(const vector<T>& data_)

		: h(ceil(log2(data_.size()))), n(1 << h), data(n * 2) {

		for (int i = 0; i < (int)data_.size(); i++) {

			data[i + n].init(data_[i]);

		}

		init();

	}

	void init() {

		for (int i = n - 1; i >= 1; i--) {

			data[i].init(data[i << 1], data[(i << 1) | 1]);

		}

	}

	void update(int l, int r, U val) {

		l += n, r += n;

		for (int i = h; i > 0; i--) push(l >> i), push(r >> i);

		int tl = l, tr = r;

		r++;

		while (l < r) {

			if (l & 1) data[l++].update(val);

			if (r & 1) data[--r].update(val);

			l >>= 1; r >>= 1;

		}

		while (tl >>= 1, tr >>= 1, tl) {

			if (!data[tl].is_updated()) update(tl);

			if (!data[tr].is_updated()) update(tr);

		}

	}

	T find(int l, int r) {

		l += n, r += n;

		for (int i = h; i > 0; i--) push(l >> i), push(r >> i);

		r++;

		T res1 = M::id(), res2 = M::id();

		while (l < r) {

			if (l & 1) res1 = M::op(res1, data[l++].get());

			if (r & 1) res2 = M::op(data[--r].get(), res2);

			l >>= 1; r >>= 1;

		}

		return M::op(res1, res2);

	}

};



int main()

{

	ios::sync_with_stdio(false), cin.tie(0);

	int n, q;

	cin >> n >> q;

	segment_tree st(n);

	while (q--) {

		int type, s, t;

		cin >> type >> s >> t; s--; t--;

		if (type) {

			printf("%lld\n", st.find(s, t));

		}

		else {

			int x;

			cin >> x;

			st.update(s, t, x);

		}

	}

	return 0;

}


