#include <iostream>

#include <cstdio>

#include <vector>

#include <cstring>

#include <algorithm>

#define int long long

using namespace std;

const int N = 1e3 + 5, M = 2e5 + 5;

int read() {

	int x = 0, f = 1; char ch;

	while(! isdigit(ch = getchar())) (ch == '-') && (f = -f);

	for(x = ch ^ 48; isdigit(ch = getchar()); x = (x << 3) + (x << 1) + (ch ^ 48));

	return x * f;

}

template <class T> T Max(T a, T b) { return a > b ? a : b; }

template <class T> T Min(T a, T b) { return a < b ? a : b; }

vector <int> v[N];

struct edge {int x, y;} e[M];

int n, m, vis[N], tag[N], g1[N][N], g2[N][N];

void dfs(int x, int rt) {

	g1[rt][x] = 1; vis[x] = 1;

	for(int i = 0; i < v[x].size(); ++ i) if(! vis[v[x][i]]) dfs(v[x][i], rt);

}

void dfs(int x, int col, int type, int rt) {

	vis[x] = 1;

	if(! type) tag[x] = col;

	else g2[rt][x] = tag[x] != col;

	for(int i = 0; i < v[x].size(); ++ i) if(! vis[v[x][i]]) dfs(v[x][i], col, type, rt);

}

signed main() {

	n = read(); m = read();

	for(int i = 1, x, y; i <= m; ++ i) {

		x = read(); y = read();

		v[x].push_back(y);

		e[i] = (edge){x, y};

	}

	for(int i = 1; i <= n; ++ i) {

		for(int j = 1; j <= n; ++ j) vis[j] = 0;

		dfs(i, i);

	}

	for(int i = 1; i <= n; ++ i) {

		for(int j = 1; j <= n; ++ j) tag[j] = vis[j] = 0; vis[i] = 1;

		for(int j = 0; j < v[i].size(); ++ j) if(! vis[v[i][j]]) dfs(v[i][j], j + 1, 0, i);

		for(int j = 1; j <= n; ++ j) vis[j] = 0; vis[i] = 1;

		for(int j = v[i].size() - 1; j >= 0; -- j) if(! vis[v[i][j]]) dfs(v[i][j], j + 1, 1, i);

	}

	for(int i = 1; i <= m; ++ i) puts(g1[e[i].y][e[i].x] ^ g2[e[i].x][e[i].y] ? "diff" : "same");

	return 0;

}
