#include "stdc++.h"

using namespace std; 

const int N = 200005;

int n;

int a[N], tot=0, h[N];

int dfn[N], low[N], sta[N], dfs_num=0, top=0;

vector<int> e[N]; 

int f[N];

bool vis[N], vis2[N];

void tarjan(int u){

	dfn[u] = low[u] = ++dfs_num;

	sta[++top] = u;

	for (int i = 0; i < e[u].size(); i++){

		int v = e[u][i];

		if (!dfn[v]){

			tarjan(v);

			low[u] = min(low[v], low[u]);

		}else if (!vis2[v]) low[u] = min(dfn[v], low[u]);

	}

	if (dfn[u] == low[u]){

		vis2[u] = 1;

		if (sta[top] == u){

			top--;

			return;

		}

		do{

			vis2[sta[top]] = 1;

			a[++tot] = sta[top];

			h[sta[top]] = 1;

		}while (sta[top--] != u);

	}

}

void dfs(int u){

	for (int i = 0; i < e[u].size(); i++){

		int v = e[u][i];

		if (!h[v]) dfs(v);

	}

    for (int i = 0; i < e[u].size(); i++){

		int v = e[u][i];

        if (!h[v]) vis[f[v]] = 1;

    }

	while (vis[f[u]]) f[u]++;

	for (int i = 0; i < e[u].size(); i++){

		int v = e[u][i];

		if (!h[v]) vis[f[v]] = 0;

	}

}

int main(){

	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//	freopen("test_file/in.txt", "r", stdin);

//	freopen("test_file/out.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++){

		int fa;

		cin >> fa;

		e[fa].push_back(i);

	}

	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);

	int mn = 0x3f3f3f3f, mx = -1;

	for (int i = 1; i <= tot; i++){

		dfs(a[i]);

		mn = min(f[a[i]], mn);

		mx = max(f[a[i]], mx);

	}

	puts((mn == mx && (tot&1) ? "IMPOSSIBLE" : "POSSIBLE"));

	return 0;

}