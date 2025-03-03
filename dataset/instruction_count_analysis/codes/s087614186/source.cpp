#include"stdc++.h"

using namespace std;



typedef long long ll;

const ll N = 1e5 + 100, inF = 1e17;

ll A, B, C, n, a[N], b[N], c[N], dex[N], up[N], down[N];



int main() {

	ios::sync_with_stdio(false), cin.tie(0);

	cin >> A >> B >> C;

	n = A + B + C;

	for (int i = 0; i < n; i++)

		cin >> a[i] >> b[i] >> c[i];

	iota(dex, dex + n, 0);

	sort(dex, dex + n, [](int x, int y) {

		return c[x] - b[x] < c[y] - b[y];

	});

	// a - b

	fill(up, up + N, -inF);

	multiset<ll> st;

	ll now = 0;

	for (int i = 0; i < B; i++) {

		int ind = dex[i];

		st.insert(a[ind] - b[ind]);

		now += b[ind];

	}

	if(B)

		up[B - 1] = now;

	for (int i = B; i < n; i++) {

		int ind = dex[i];

		if(B == 0) {

			now += a[ind];

			up[i] = now;

			continue;

		}

		if(a[ind] - b[ind] > (*st.rbegin()))

			now += a[ind];

		else {

			ll val = *st.rbegin();

			st.erase(st.find(val));

			now += val;

			now += b[ind];

			st.insert(a[ind] - b[ind]);

		}

		up[i] = now;

	}

	// a - c

	fill(down, down + N, -inF);

	st.clear();

	now = 0;

	for (int i = 0; i < C; i++) {

		int ind = dex[n - i -1];

		st.insert(a[ind] - c[ind]);

		now += c[ind];

	}

	down[n - C] = now;

	for (int i = C; i < n; i++) {

		int ind = dex[n - i - 1];

		if(C == 0) {

			now += a[ind];

			down[i] = now;

			continue;

		}

		if(a[ind] - c[ind] > (*st.rbegin()))

			now += a[ind];

		else {

			ll val = *st.rbegin();

			st.erase(st.find(val));

			now += val;

			now += c[ind];

			st.insert(a[ind] - c[ind]);

		}

		down[n - i - 1] = now;

	}

	ll ans = 0;

	for (int i = 0; i < n - 1; i++)

		ans = max(ans, up[i] + down[i + 1]);

	cout << ans;

	return 0;

}