#include "stdc++.h"

using namespace std;

typedef long long ll;

const int N = 1 << 17;

struct Segt {

	ll sum[N << 1], add[N << 1];

	Segt() {

		memset(sum, 0, sizeof sum);

		memset(add, 0, sizeof add);

	}

	void pd(int i, int l) {

		if (add[i]) {

			sum[i] += add[i] * l;

			if (i < N) {

				add[i + i] += add[i];

				add[i + i + 1] += add[i];

			}

			add[i] = 0;

		}

	}

	void upd(int i, int a, int b, int l, int r, int v) {

		if (l <= a && b <= r) {

			add[i] += v;

			pd(i, b - a); return;

		}

		pd(i, b - a);

		if (r <= a || b <= l) return;

		int md = (a + b) >> 1;

		upd(i + i, a, md, l, r, v);

		upd(i + i + 1, md, b, l, r, v);

		sum[i] = sum[i + i] + sum[i + i + 1];

	}

	ll qry(int i, int a, int b, int l, int r) {

		pd(i, b - a);

		if (l <= a && b <= r) return sum[i];

		if (r <= a || b <= l) return 0;

		int md = (a + b) >> 1;

		ll L = qry(i + i, a, md, l, r);

		ll R = qry(i + i + 1, md, b, l, r);

		return L + R;

	}

} segt;

int n, m;

int a[N];

int main() {

	ios :: sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++ i) cin >> a[i], -- a[i];

	ll tot = 0;

	for (int i = 0; i + 1 < n; ++ i) {

		if (a[i] < a[i + 1]) {

			tot += a[i + 1] - a[i];

			segt.upd(1, 0, N, a[i] + 2, a[i + 1] + 1, 1);

			segt.upd(1, 0, N, a[i + 1] + 1, a[i + 1] + 2, -(a[i + 1] - a[i] - 1));

		} else {

			tot += m - a[i] + a[i + 1];

			segt.upd(1, 0, N, a[i] + 2, m, 1);

			segt.upd(1, 0, N, 0, 1, m - a[i] - 1);

			segt.upd(1, 0, N, 1, a[i + 1] + 1, 1);

			segt.upd(1, 0, N, a[i + 1] + 1, a[i + 1] + 2, -(m - a[i] + a[i + 1] - 1));

		}

//		for (int j = 0; j < m; ++ j) cerr << segt.qry(1, 0, N, 0, j + 1) << " "; cerr << endl;

	}

	cerr << tot << endl;

	ll mx = 0;

	for (int i = 0; i < m; ++ i) {

		ll cur = segt.qry(1, 0, N, 0, i + 1);

//		cerr << i << ": " << cur << endl;

		mx = max(mx, cur);

	}

	cout << tot - mx << endl;

	return 0;

}