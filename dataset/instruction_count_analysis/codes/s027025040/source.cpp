#include "stdc++.h"

#define MAX 100000

using namespace std;

using pi = pair<int, int>;



template <typename T>

class SegmentTree {

	using func_t = function<T(T, T)>;

	const int n;

	const T id;

	func_t merge;

	vector<T> data;

	int size(int n) {

		int res;

		for (res = 1; res < n; res <<= 1);

		return res;

	}

	T sub(int l, int r, int node, int lb, int ub) const {

		if (ub <= l || r <= lb) return id;

		if (l <= lb && ub <= r) return data[node];

		return merge(sub(l, r, node * 2, lb, (lb + ub) / 2), sub(l, r, node * 2 + 1, (lb + ub) / 2, ub));

	}

public:

	SegmentTree(int n_, T id_, func_t merge_) :

		n(size(n_)), id(id_), merge(merge_), data(size(n_) * 2, id_) {}

	SegmentTree(const vector<T>& data_, T id_, func_t merge_) :

		n(size(data_.size())), id(id_), merge(merge_), data(size(data_.size()) * 2, id_) {

		for (int i = 0; i < (int)data_.size(); i++)

			data[i + n] = data_[i];

		for (int i = n - 1; i >= 0; i--)

			data[i] = merge(data[i * 2], data[i * 2 + 1]);

	}

	void Update(int p, T val) {

		p += n;

		data[p] = val;

		while (p >>= 1) data[p] = merge(data[p * 2], data[p * 2 + 1]);

	}

	void Add(int p, T val) {

		p += n;

		data[p] += val;

		while (p >>= 1) data[p] = merge(data[p * 2], data[p * 2 + 1]);

	}

	T Find(int l, int r) const {

		return sub(l, r + 1, 1, 0, n);

	}

	T operator[](int i) const {

		return data[i + n];

	}

};



int N, rt;

vector<int> G[MAX];

int depth[MAX], used[MAX], id[MAX];

vector<int> vs, de;



void Add(int a, int b) {

	G[a].push_back(b);

	G[b].push_back(a);

}



void dfs(int s, int d) {

	used[s] = 1;



	vs.push_back(s);

	de.push_back(d);

	for (int v : G[s]) {

		if (!used[v]) {

			dfs(v, d + 1);



			vs.push_back(s);

			de.push_back(d);

		}

	}

}



SegmentTree<pi> Init() {

	fill(used, used + N, 0);

	fill(id, id + N, -1);

	dfs(rt, 0);

	for (int i = 0; i < (int)vs.size(); i++) {

		if (id[vs[i]] == -1) {

			id[vs[i]] = i;

		}

	}

	vector<pi> r((int)vs.size());

	for (int i = 0; i < (int)vs.size(); i++) {

		r[i] = pi(de[i], vs[i]);

	}

	SegmentTree<pi> res(r, pi(N, -1), [](pi a, pi b) { return a.first <= b.first ? a : b; });

	for (int i = 0; i < N; i++) {

		depth[i] = res[id[i]].first;

	}

	return res;

}



int LCA(const SegmentTree<pi>& st, int a, int b) {

	return st.Find(min(id[a], id[b]), max(id[a], id[b])).second;

}



int main()

{

	cin >> N;

	for (int i = 0, k; i < N; i++) {

		cin >> k;

		for (int j = 0, c; j < k; j++) {

			cin >> c;

			Add(i, c);

		}

	}

	int Q, a, b;

	auto st = Init();

	cin >> Q;

	while (Q--) {

		cin >> a >> b;

		cout << LCA(st, a, b) << endl;

	}

	return 0;

}