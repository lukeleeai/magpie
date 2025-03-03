#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef pair<bool , bool> pii;

typedef pair<ll, ll> pll;



#define $ system("pause")

#define MOD ll(1e9 + 7)

#define MAXN 300010

#define inf (ll)1e18



template<typename T> inline T smin(T &a, const T &b) { return a > b ? a = b : a; }

template<typename T> inline T smax(T &a, const T &b) { return a < b ? a = b : a; }

inline void add(ll &l, const ll &r) { l = (l + r) % MOD; }

ll gcd(ll v, ll u) { return u ? gcd(u, v % u) : v; }

ll po(ll v, ll u) { return u ? (po(v * v % MOD, u >> 1) * (u & 1 ? v : 1) % MOD) : 1; }



/*

int n, arr[MAXN];

int have[MAXN][20];

int pl[MAXN][20], pr[MAXN][20];

vector<int> p[MAXN];



int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 2; i < MAXN; i++)

		if (p[i].empty()) {

			for (int j = i; j < MAXN; j += i)

				p[j].push_back(i);

		}



	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> arr[i];

		int local = arr[i];

		for (auto e : p[arr[i]]) {

			int cnt = 0;

			while ((local % e) == 0) {

				cnt++;

				local /= e;

			}

			have[e][cnt]++;

		}

	}

	for (int i = 1; i < MAXN; i++) {

		pr[i][19] = have[i][19];

		for (int j = 18; j; j--) 

			pr[i][j] = pr[i][j + 1] + have[i][j];

		have[i][0] = n - pr[i][1];

		pr[i][0] = n;

		pl[i][0] = have[i][0];

		for (int j = 1; j < 20; j++)

			pl[i][j] = pl[i][j - 1] + have[i][j];



	}

	return 0;

}



*/



int n, arr[MAXN];

vector<int> adj[MAXN];



bool dfs(int v, int p = 0) {

	bool res = false;

	for (auto e : adj[v]) {

		if (e ^ p && arr[e] < arr[v]) {

			res |= !dfs(e, v);

		}

	}

	return res;

}



int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)

		cin >> arr[i];

	for (int i = 1; i < n; i++) {

		int u, v; cin >> u >> v;

		adj[u].push_back(v);

		adj[v].push_back(u);

	}

	for (int i = 1; i <= n; i++) {

		if (dfs(i))

			cout << i << ' ';

	}

	//$;

	return 0;

}