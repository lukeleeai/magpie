#include "stdc++.h"

#include <unordered_map>

using namespace std;

using ll = long long;



template <typename T>

class FenwickTree {

	const ll n;

	unordered_map<ll, T> data;

public:

	FenwickTree(ll n_, int pmax = 1e5) : n(n_), data(pmax) {}

	T find(ll p) {

		T res = 0;

		while (p >= 0) {

			res += data[p];

			p = (p & (p + 1)) - 1;

		}

		return res;

	}

	void add(ll p, T val) {

		while (p < n) {

			data[p] += val;

			p |= p + 1;

		}

	}

};



template <typename T>

class RARS {

	const ll n;

	FenwickTree<T> bit0, bit1;

public:

	RARS(ll n_) : n(n_), bit0(n), bit1(n) {}

	T find(ll p) {

		return bit1.find(p) * (p + 1) + bit0.find(p);

	}

	T find(ll l, ll r) {

		return find(r) - find(l - 1);

	}

	void add(ll l, ll r, T val) {

		bit0.add(l, -val * l);

		bit1.add(l, val);

		bit0.add(r + 1, val * (r + 1));

		bit1.add(r + 1, -val);

	}

};



int main()

{

	ios::sync_with_stdio(false), cin.tie(0);

	int n, q;

	cin >> n >> q;

	RARS<ll> rars(n);

	for (int i = 0, type, s, t, x; i < q; i++) {

		cin >> type >> s >> t; s--; t--;

		if (type) {

			printf("%lld\n", rars.find(s, t));

		}

		else {

			cin >> x;

			rars.add(s, t, x);

		}

	}

	return 0;

}


