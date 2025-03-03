#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<algorithm>

#include<cmath>

#include<vector>

#include<set>

#include<map>

#include<unordered_set>

#include<unordered_map>

#include<queue>

#include<ctime>

#include<cassert>

#include<complex>

#include<string>

#include<cstring>

#include<chrono>

#include<random>

#include<bitset>

#include<iomanip>



#define fi first

#define se second

#define mp make_pair

#define eb emplace_back

#define all(v) v.begin(), v.end()

#define sz(v) (int) v.size()



using namespace std;



mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());



typedef long long ll;

typedef long double ld;

typedef unsigned long long ull;

typedef pair<int, int> pii;



const int MAX_N = 1e5 + 5;



int n, a[MAX_N];

int pref[MAX_N], fenw[MAX_N * 2];



void update(int pos, int delta) {

	for (int i = pos; i <= 2 * n; i |= (i + 1)) {

		fenw[i] += delta;

	}

}



int get(int r) {

	int res = 0;

	for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {

		res += fenw[i];

	}

	return res;

}



bool check(int m) {

	fill(fenw, fenw + 2 * n + 1, 0);

	for (int i = 1; i <= n; ++i) {

		pref[i] = pref[i - 1] + (a[i] >= m) - (a[i] < m);

	}

	update(n, 1);

	ll cnt = 0;

	for (int i = 1; i <= n; ++i) {

		cnt += get(pref[i] + n);

		update(pref[i] + n, 1);

	}

	return cnt >= (1ll * n * (n + 1) / 2 + 1) / 2;

}



signed main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cin >> n;

	vector<int> diff;

	for (int i = 1; i <= n; ++i) {

		cin >> a[i];

		diff.eb(a[i]);

	}

	sort(all(diff));

	diff.resize(unique(all(diff)) - diff.begin());

	int lef = 0, rig = sz(diff);

	while (lef + 1 < rig) {

		int mid = (lef + rig) / 2;

		if (check(diff[mid])) {

			lef = mid;

		} else {

			rig = mid;

		}

	}

	cout << diff[lef] << "\n";

	return 0;

}