#include <algorithm>

#include <iostream>

#include <vector>

using namespace std;



typedef long long ll;

const int MAXN = 1e5 + 10;

ll n, a[MAXN], b[MAXN], C;

vector<ll> p, Mat[MAXN];

bool isp[MAXN], se[MAXN];

int cnt[MAXN], sh, shr;



ll getmsk(ll t) {

	for (int i = 0; p[i] * p[i] * p[i] <= t; i++) {

		ll r = p[i] * p[i] * p[i];

		while (t % r == 0)

			t /= r;

	}

	return t;

}

ll rmsk(ll t) {

	ll m = 1;

	for (int i = 0; p[i] * p[i] <= t; i++) {

		if (t % (p[i] * p[i]) == 0)

			m *= p[i], t /= p[i] * p[i];

		else if (t % p[i] == 0)

			m *= p[i] * p[i], t /= p[i];

	}

	if (t != 1)

		m *= t * t;

	return m;

}



void dfs(int v, bool cl) {

	se[v] = 1;

	sh += cnt[v];

	if (cl)

		shr += cnt[v];

	for (int i = 0; i < Mat[v].size(); i++)

		if (!se[Mat[v][i]])

			dfs(Mat[v][i], !cl);

}



int main() {

	for (int i = 2; i < MAXN; i++)

		if (!isp[i]) {

			p.push_back(i);

			for (int j = i; j < MAXN; j += i)

				isp[j] = 1;

		}

	cin >> n;

	for (int i = 0; i < n; i++)

		cin >> a[i], a[i] = getmsk(a[i]);

	sort(a, a + n);

	for (int i = 0; i < n;) {

		b[C] = a[i];

		while (i < n && a[i] == b[C])

			cnt[C]++, i++;

		C++;

	}

	for (int i = (a[0] == 1); i < C; i++) {

		ll t = rmsk(b[i]);

		int f = lower_bound(b, b + C, t) - b;

		if (f == C || b[f] != t)

			continue;

		Mat[i].push_back(f);

	}

	int ans = 0;

	for (int i = (b[0] == 1); i < C; i++)

		if (!se[i]) {

			sh = shr = 0;

			dfs(i, 0);

			ans += max(shr, sh - shr);

		}

	ans += b[0] == 1;

	cout << ans;

}