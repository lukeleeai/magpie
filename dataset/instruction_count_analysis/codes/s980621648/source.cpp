#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cstring> 

#include <cmath> 

#include <algorithm>

#include <vector> 

using namespace std; 

inline int gi() {

    register int data = 0, w = 1;

    register char ch = 0;

    while (!isdigit(ch) && ch != '-') ch = getchar(); 

    if (ch == '-') w = -1, ch = getchar(); 

    while (isdigit(ch)) data = 10 * data + ch - '0', ch = getchar(); 

    return w * data; 

} 

const int MAX_N = 1e5 + 5; 

int N, M, a[MAX_N], b[MAX_N], p[MAX_N]; 

int pa[MAX_N]; 

int getf(int x) { while (x != pa[x]) x = pa[x] = pa[pa[x]]; return x; } 

vector<int> G[MAX_N]; 

long long f[MAX_N], sum[MAX_N];

bool vis[MAX_N]; 

int main () { 

	N = gi(), M = gi();

	for (int i = 1; i <= N; i++) { 

		a[i] = gi(), b[i] = gi(); 

		a[i] = max(a[i] - b[i], 0);

		p[i] = i, pa[i] = i; 

	} 

	sort(&p[1], &p[N + 1], [](const int &l, const int &r) { return a[l] < a[r]; } ); 

	for (int i = 1; i <= M; i++) { 

		int u = gi(), v = gi(); 

		G[u].push_back(v), G[v].push_back(u); 

	} 

	for (int i = 1; i <= N; i++) { 

		vector<int> son;

		int x = p[i]; 

		vis[x] = 1, sum[x] = b[x]; 

		for (auto v : G[x]) {

			if (!vis[v] || getf(x) == getf(v)) continue; 

			son.push_back(getf(v)); 

			sum[x] += sum[getf(v)]; 

			pa[getf(v)] = x; 

		} 

		f[x] = sum[x] + a[x]; 

		for (auto v : son) f[x] = min(f[x], sum[x] - sum[v] + max(1ll * a[x], f[v])); 

	} 

	printf("%lld\n", f[p[N]]); 

    return 0; 

} 