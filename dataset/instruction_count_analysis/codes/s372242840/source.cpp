#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <cmath>

#include <vector>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <queue>

#include <ctime>

#include <cassert>

#include <complex>

#include <string>

#include <cstring>

#include <chrono>

#include <random>

#include <queue>

#include <bitset>

using namespace std;



#ifdef LOCAL

	#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#else

	#define eprintf(...) 42

#endif



typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, int> pli;

typedef pair<ll, ll> pll;

typedef long double ld;

#define mp make_pair

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



const int N = 100100;

int n;

vector<int> g[N];

int dp[N];



void dfs(int v, int par) {

	int p = 0, x = 0;

	for (int u : g[v]) {

		if (u == par) continue;

		dfs(u, v);

		while(x & dp[u]) {

			p++;

			x ^= x & ((1 << p) - 1);

		}

		x |= dp[u];

		x ^= x & ((1 << p) - 1);

	}

	dp[v] = x + (1 << p);

}



int main()

{

//	freopen("input.txt", "r", stdin);

//	freopen("output.txt", "w", stdout);



	scanf("%d", &n);

	for (int i = 1; i < n; i++) {

		int v, u;

		scanf("%d%d", &v, &u);

		v--;u--;

		g[v].push_back(u);

		g[u].push_back(v);

	}

	dfs(0, -1);

	int ans = 0;

	while((1 << ans) <= dp[0]) ans++;

	printf("%d\n", ans - 1);



	return 0;

}
