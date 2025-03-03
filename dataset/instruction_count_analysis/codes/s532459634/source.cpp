/*

Date&Time: 12:19pm 3/10/2020

*/



#include "stdc++.h"



using namespace std;



#define int long long



const int N = 2e5 + 10;



int ver[N * 2], nex[N * 2], head[N], cnt[2], ans[N], color[N];

int n, tot;

vector<int> a[3];



inline void add(int x, int y) {

	ver[++tot] = y;

	nex[tot] = head[x];

	head[x] = tot;

}



void dfs(bool c, int x, int fa) {

	color[x] = c;

	cnt[c]++;

	for (int i = head[x]; i; i = nex[i]) {

		int y = ver[i];

		if (y == fa) continue;

		dfs(!c, y, x);

	}

}



signed main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {

		a[i % 3].push_back(i);

	}

	for (int i = 1, u, v; i < n; i++) {

		cin >> u >> v;

		add(u, v), add(v, u);

	}

	dfs(1, 1, 0);

	int fl = 0;

	int r = cnt[0], b = cnt[1];

	if (r > b) swap(r, b), fl = !fl;

	int x = n / 3;

	int zero = 0, one = 0, two = 0;

	if (r <= x) {

		for (int i = 1; i <= n; i++) {

			if (color[i] == fl) {

				ans[i] = a[0][zero++];

			}

			else {

				ans[i] = one < a[1].size() ? a[1][one++] : two < a[2].size() ? a[2][two++] : a[0][zero++];

			}

		}

	}

	else{

		for (int i = 1; i <= n; i++) {

			if (color[i] == fl) {

				ans[i] = one < a[1].size() ? a[1][one++] : zero < a[0].size() ? a[0][zero++] : a[1][one++];

			}

			else {

				ans[i] = two < a[2].size() ? a[2][two++] : zero < a[0].size() ? a[0][zero++] : a[1][one++];

			}

		}

	}

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

	cout << '\n';

}